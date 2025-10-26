class TimeMap {
public:
    unordered_map<string, set<pair<int, string>>> mp;
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& st = mp[key];
        auto ptr = st.upper_bound({timestamp, string(1, char(255))});
        if (ptr == st.begin()) return "";
        ptr--;
        return ptr->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
