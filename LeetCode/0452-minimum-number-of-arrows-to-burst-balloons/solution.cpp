class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {return a[0] < b[0];});

        int n = points.size();
        int ans=0;
        long long start=points[0][0], end=points[0][1];
        for (int i=1; i<n; i++) {
            long long curStart=points[i][0], curEnd=points[i][1];
            long long curRange = min(end, curEnd) - max(start, curStart);
            if (curStart > end) {
                ans++;
                start = curStart;
                end = curEnd;
            }
            else {
                start = max(start, curStart);
                end = min(end, curEnd);
            }
        }
        return ans+1;
    }
};
