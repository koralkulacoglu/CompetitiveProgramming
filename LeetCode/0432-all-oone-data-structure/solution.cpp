class AllOne {
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };

    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> loc;

public:
    void inc(string key) {
        auto it = loc.find(key);
        if (it == loc.end()) {
            if (buckets.empty() || buckets.front().count != 1) buckets.push_front({1, {}});
            buckets.front().keys.insert(key);
            loc[key] = buckets.begin();
            return;
        }

        auto cur = it->second;
        int target = cur->count + 1;
        auto nxt = next(cur);

        if (nxt == buckets.end() || nxt->count != target) nxt = buckets.insert(nxt, {target, {}});

        nxt->keys.insert(key);
        loc[key] = nxt;

        cur->keys.erase(key);
        if (cur->keys.empty()) buckets.erase(cur);
    }
    
    void dec(string key) {
        auto cur = loc[key];
        if (cur->count == 1) loc.erase(key);
        else {
            auto prev = std::prev(cur);
            if (cur == buckets.begin() || prev->count != cur->count - 1) prev = buckets.insert(cur, {cur->count - 1, {}});
            prev->keys.insert(key);
            loc[key] = prev;
        }

        cur->keys.erase(key);
        if (cur->keys.empty()) buckets.erase(cur);
    }
    
    string getMaxKey() {
        if (buckets.empty()) return "";
        return *(buckets.back().keys.begin());
    }
    
    string getMinKey() {
        if (buckets.empty()) return "";
        return *(buckets.front().keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
