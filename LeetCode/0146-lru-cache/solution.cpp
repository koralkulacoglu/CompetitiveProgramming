class LRUCache {
    int n;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> window;

public:
    LRUCache(int capacity) : n(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        window.splice(window.end(), window, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            window.erase(it->second);
            window.push_back(make_pair(key, value));
            cache[key] = prev(window.end());
        }
        else {
            window.push_back(make_pair(key, value));
            auto it = window.end();
            it--;
            cache[key] = it;

            if (window.size() <= n) return;

            auto it2 = window.front();
            int key = it2.first;
            
            cache.erase(key);
            window.pop_front();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
