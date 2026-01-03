class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<pair<int, int>> less, val, greater;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > pivot) greater.push_back(make_pair(i, nums[i]));
            else if (nums[i] < pivot) less.push_back(make_pair(i, nums[i]));
            else val.push_back(make_pair(i, nums[i]));
        }
        sort(less.begin(), less.end());
        sort(greater.begin(), greater.end());
        sort(val.begin(), val.end());
        
        vector<int> res;
        for (auto i : less) res.push_back(i.second);
        for (auto i : val) res.push_back(i.second);
        for (auto i : greater) res.push_back(i.second);
        
        return res;
    }
};
