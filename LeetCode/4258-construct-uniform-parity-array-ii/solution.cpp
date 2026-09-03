class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int o=0, e=0, mnO=1e9, mnE=1e9;
        for (int i : nums1) {
            if (i%2) {
                o++;
                mnO = min(mnO, i);
            }
            else {
                e++;
                mnE = min(mnE, i);
            }
        }
        if (!o || !e) return true;
        return mnO < mnE;
    }
};
