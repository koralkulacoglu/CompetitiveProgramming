class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> a) {
        int n = a.size();

        if (n <= 1) return a;

        if (n == 2) {
            if (a[0][1] >= a[1][0]) return {{a[0][0], max(a[0][1], a[1][1])}};
            return a;
        }

        vector<vector<int>> left(a.begin(), a.begin() + n/2);
        vector<vector<int>> right(a.begin() + n/2, a.end());

        vector<vector<int>> mergedLeft = mergeIntervals(left);
        vector<vector<int>> mergedRight = mergeIntervals(right);

        vector<vector<int>> res;

        for (const auto& i : mergedLeft) res.push_back(i);
        for (const auto& i : mergedRight) res.push_back(i);

        vector<vector<int>> merged;
        merged.push_back(res[0]);

        for (int i = 1; i < res.size(); ++i) {
            if (merged.back()[1] >= res[i][0]) {
                merged.back()[1] = max(merged.back()[1], res[i][1]);
            } else {
                merged.push_back(res[i]);
            }
        }

        return merged;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        return mergeIntervals(intervals);
    }
};
