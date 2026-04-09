class TimeMap {
    unordered_map<string, set<pair<int, string>>> mp;
public:
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound({timestamp, string(1, char(255))});
        if (it == mp[key].begin()) return "";
        return (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
