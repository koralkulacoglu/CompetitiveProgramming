class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        unordered_map<int, int> vis;
        for (int i=0; i<n; i++) {
            if (vis[target-numbers[i]]) {
                return {vis[target-numbers[i]], i+1};
            }
            vis[numbers[i]] = i+1;
        }
        return {-1, -1};
    }
};
