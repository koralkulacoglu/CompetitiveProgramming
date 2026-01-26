class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int minDiff = 1e9;
        for (int i=1; i<n; i++) {
            minDiff = min(minDiff, abs(arr[i] - arr[i-1]));
        }

        vector<vector<int>> res;
        for (int i=1; i<n; i++) {
            int curDiff = abs(arr[i] - arr[i-1]);
            if (curDiff == minDiff) res.push_back({min(arr[i], arr[i-1]), max(arr[i], arr[i-1])});
        }

        sort(res.begin(), res.end());
        
        return res;
    }
};
