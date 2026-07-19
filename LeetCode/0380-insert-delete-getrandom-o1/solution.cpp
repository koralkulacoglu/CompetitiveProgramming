class RandomizedSet {
    vector<pair<int, bool>> vals;
    unordered_map<int, int> idx;
public:
    RandomizedSet() = default;
    
    bool insert(int val) {
        if (idx.find(val) != idx.end()) return false;

        vals.emplace_back(val, true);

        idx[val] = vals.size() - 1;

        return true;
    }
    
    bool remove(int val) {
        if (idx.find(val) == idx.end()) return false;

        int i = idx[val];
        vals[i].second = false;

        idx.erase(val);

        return true;
    }
    
    int getRandom() {
        int n = vals.size();
        while (true) {
            int i = rand() % n;
            if (vals[i].second) return vals[i].first;
        }
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
