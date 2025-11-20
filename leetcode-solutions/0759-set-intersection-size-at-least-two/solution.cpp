class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });

        int p1 = -1;
        int p2 = -1;
        int res = 0;
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            bool p1_in = (start <= p1);
            bool p2_in = (start <= p2);

            if (p1_in && p2_in) {
                continue;
            } 
            else if (p2_in) {
                res++;
                p1 = p2;
                p2 = end;
            } 
            else {
                res += 2;
                p1 = end - 1;
                p2 = end;
            }
        }

        return res;
    }
};
