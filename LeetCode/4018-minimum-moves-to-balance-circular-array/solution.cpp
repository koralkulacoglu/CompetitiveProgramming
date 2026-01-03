class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();

        long long total = accumulate(balance.begin(), balance.end(), 0LL);
        if (total < 0) return -1;

        int idx = -1;
        for (int i=0; i<n; i++) {
            if (balance[i] < 0) {
                idx = i;
                break;
            }
        }

        if (idx == -1) return 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i=0; i<n; i++) {
            if (i == idx) continue;
            int cnt = balance[i];
            int dist = min(abs(idx - i), (n - max(i, idx) + min(i, idx)));
            pq.push({dist, cnt});
        }

        int needed = -balance[idx];
        long long ans = 0;
        while (!pq.empty()) {
            if (needed == 0) break;
            
            auto best = pq.top(); pq.pop();
            int dist = best.first;
            int cnt = best.second;

            int use = min(needed, cnt);
            needed -= use;
            ans += ((long long)use) * dist;
            // cout << dist << ' ' << use << endl;
        }

        return (needed ? -1 : ans);
    }
};
