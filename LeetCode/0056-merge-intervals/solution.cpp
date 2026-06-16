class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int n = intervals.size();
        for (int i=1; i<n; i++) {
            int m = res.size();

            int& start = intervals[i][0];
            int& end = intervals[i][1];

            int& prevStart = res[m-1][0];
            int& prevEnd = res[m-1][1];

            if (prevEnd < start) res.push_back(intervals[i]);
            else res[m-1][1] = max(end, prevEnd);
        }

        return res;
    }
};
