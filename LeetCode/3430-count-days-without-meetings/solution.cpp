class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        int ans = 0;
        int day = 1;
        for (auto meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            if (start > day) ans += start - day;
            day = max(day, end + 1);
        }
        if (days >= day) ans += days - day + 1;
        return ans;
    }
};
