typedef tuple<long long, long long, long long> Entry;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<Entry, vector<Entry>, greater<Entry>> pq;
        for (int t : workerTimes) pq.push({t, t, 1});
        long long ans = 0;
        for (int i=0; i<mountainHeight; i++) {
            auto [totalSeconds, workerTime, x] = pq.top();
            pq.pop();
            ans = max(ans, totalSeconds);
            pq.push({totalSeconds + workerTime * (x + 1), workerTime, x + 1});
        }
        return ans;
    }
};
