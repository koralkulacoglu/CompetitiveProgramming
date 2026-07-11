class Skiplist {
    struct Node {
        int value;
        Node* next{nullptr};
        Node* below{nullptr};
    };

    int capacity{32};
    vector<Node*> data;

    int getHeight() {
        int height = 1;
        while (height < capacity && rand() % 2 == 0) {
            height++;
        }

        return height;
    }

public:
    Skiplist() : data(capacity) {
        for (int i=capacity-1; i>=0; i--) {
            data[i] = new Node(-1e9);
            data[i]->next = new Node(1e9);

            if (i < capacity - 1) {
                data[i]->below = data[i+1];
                data[i]->next->below = data[i+1]->next;
            }
        }
    }

    vector<Node*> findPredecessors(int target) {
        vector<Node*> pres;
        Node* temp = data[0];

        while (temp != nullptr) {
            while (temp->next->value < target) temp = temp->next;
            pres.push_back(temp);
            temp = temp->below;
        }

        return pres;
    }
    
    bool search(int target) {
        vector<Node*> pres = findPredecessors(target);
        if (pres.empty()) return false;
        return pres[pres.size() - 1]->next->value == target;
    }
    
    void add(int num) {
        vector<Node*> pres = findPredecessors(num);
        int n = pres.size();

        // only need last height predecesorrs
        int height = getHeight();

        for (int i=0; i<height; i++) {
            Node* pre = pres[n - i - 1];

            Node* belowPtr = nullptr;

            if (i > 0) {
                belowPtr = pres[n - i]->next;
            }

            pre->next = new Node(num, pre->next, belowPtr);
        }
    }
    
    bool erase(int num) {
        vector<Node*> pres = findPredecessors(num);
        int n = pres.size();

        if (pres.empty()) return false;
        if (pres[n - 1]->next->value != num) return false;

        for (int i=0; i<n; i++) {
            Node* pre = pres[n - i - 1];

            Node* cur = pre->next;

            if (cur->value != num) break;

            pre->next = cur->next;
            cur->next = nullptr;
            cur->below = nullptr;

            delete cur;
        }

        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
