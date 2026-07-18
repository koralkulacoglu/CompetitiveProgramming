class MapSum {
    unordered_map<string, int> keyVal;

    struct Trie {
        vector<Trie*> children = vector<Trie*>(26, nullptr);
        int val{0};
    };

    Trie* trie;

public:
    MapSum() {
        trie = new Trie();
    }

    int idx(char c) {
        return c - 'a';
    }

    void insertTrie(string key, int val) {
        Trie* temp = trie;

        for (char c : key) {
            if (temp->children[idx(c)] == nullptr) {
                temp->children[idx(c)] = new Trie();
            }
            temp->val += val;
            temp = temp->children[idx(c)];
        }
        temp->val += val;
    }

    void removeTrie(string key, int val) {
        Trie* temp = trie;

        for (char c : key) {
            if (temp->children[idx(c)] == nullptr) {
                temp->children[idx(c)] = new Trie();
            }
            temp->val -= val;
            temp = temp->children[idx(c)];
        }
        temp->val -= val;
    }
    
    void insert(string key, int val) {
        auto it = keyVal.find(key);

        if (it != keyVal.end()) {
            removeTrie(key, it->second);
        }

        keyVal[key] = val;
        insertTrie(key, val);
    }
    
    int sum(string prefix) {
        Trie* temp = trie;

        for (char c : prefix) {
            // cout << c << ' ' << temp->val << endl;
            if (temp->children[idx(c)] == nullptr) return 0;
            temp = temp->children[idx(c)];
        }

        // cout << endl;

        return temp->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
