class RandomizedCollection {
    vector<pair<int, bool>> vals; // value, is valid
    unordered_map<int, vector<int>> valIdxs;
public:
    RandomizedCollection() = default;
    
    bool insert(int val) {
        bool present = (valIdxs.find(val) != valIdxs.end());
        vals.emplace_back(val, true);
        valIdxs[val].push_back(vals.size() - 1);

        return !present;
    }
    
    bool remove(int val) {
        auto it = valIdxs.find(val);

        if (it == valIdxs.end()) return false;

        int idx = it->second.back();
        it->second.pop_back();

        if (it->second.size() == 0) valIdxs.erase(it);

        vals[idx].second = false;

        return true;
    }
    
    int getRandom() {
        int n = vals.size();
        while (true) {
            int idx = rand() % n;

            if (vals[idx].second) return vals[idx].first;
        }

        return -1;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
