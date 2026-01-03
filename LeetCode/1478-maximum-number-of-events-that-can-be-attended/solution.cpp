class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0, n = events.size(), day = 1, ans = 0;
        while (!pq.empty() || i < n) {
            // Add all events starting today
            while (i < n && events[i][0] == day)
                pq.push(events[i++][1]);

            // Remove events that have already ended
            while (!pq.empty() && pq.top() < day)
                pq.pop();

            // Attend the event with the earliest end date
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }

            day++;
        }

        return ans;
    }
};
