class SnapshotArray {
    int n;
    int snap_id{0};
    vector<vector<pair<int, int>>> array;

public:
    SnapshotArray(int length) : n(length), array(length, {make_pair(0, 0)}) {}
    
    void set(int index, int val) {
        if (!array[index].empty() && array[index].back().first == snap_id) {
            array[index].back().second = val;
        }
        else {
            array[index].emplace_back(snap_id, val);
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto& arr = array[index];

        auto it = upper_bound(arr.begin(), arr.end(), make_pair(snap_id, (int)1e9));
        it--;

        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
