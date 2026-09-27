struct Node {
    int val;
    int height;
    int size;
    Node *left, *right;
    
    Node(int v) : val(v), height(1), size(1), left(nullptr), right(nullptr) {}
};

class OrderStatisticTree {
private:
    Node* root = nullptr;

    int getSize(Node* n) { return n ? n->size : 0; }
    int getHeight(Node* n) { return n ? n->height : 0; }

    void update(Node* n) {
        if (n) {
            n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
            n->size = 1 + getSize(n->left) + getSize(n->right);
        }
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        update(y);
        update(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        update(x);
        update(y);
        return y;
    }

    int getBalance(Node* n) { return n ? getHeight(n->left) - getHeight(n->right) : 0; }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }

        update(node);
        int balance = getBalance(node);

        if (balance > 1 && val < node->left->val)
            return rightRotate(node);

        if (balance < -1 && val >= node->right->val)
            return leftRotate(node);

        if (balance > 1 && val >= node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && val < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    int find_by_order(Node* node, int k) {
        int leftSize = getSize(node->left);
        if (k == leftSize) return node->val;
        if (k < leftSize) return find_by_order(node->left, k);
        return find_by_order(node->right, k - leftSize - 1);
    }

    int order_of_key(Node* node, int val) {
        if (!node) return 0;
        if (val <= node->val) {
            return order_of_key(node->left, val);
        } else {
            return 1 + getSize(node->left) + order_of_key(node->right, val);
        }
    }

public:
    void insert(int val) { root = insert(root, val); }
    int find_by_order(int k) { return find_by_order(root, k); }
    int order_of_key(int val) { return order_of_key(root, val); }
};


class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        long long ans = 0;
        OrderStatisticTree ends;
        for (int i=0; i<n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            ans += i - ends.order_of_key(start);
            ends.insert(end);
        }
        return ans;
    }
};
