class Solution {
    int n;
    vector<int> arr;
public:
    Solution(vector<int>& nums) : n(nums.size()), arr(nums) {}
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> cp = arr;

        for (int i=0; i<1e2; i++) {
            int idx1 = rand() % n;
            int idx2 = rand() % n;
            swap(cp[idx1], cp[idx2]);
        }

        return cp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
