#include <bits/stdc++.h>
using namespace std;

struct Stream {
    // current position and its clearance value
    long long p, val;
    // advance by: p += dir, val -= 1, remaining-- until remaining==0
    int dir;             // +1 or -1
    long long remaining; // how many positions (including current) left
    // for priority queue (max by val, tie-break by p just for determinism)
    bool operator<(Stream const& other) const {
        if (val != other.val) return val < other.val;
        return p < other.p;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int m = (int)a.size();

        // Build streams
        priority_queue<Stream> pq;
        auto push_stream = [&](long long start_p, long long start_val, int dir, long long cnt) {
            if (cnt <= 0 || start_val <= 0) return;
            pq.push(Stream{start_p, start_val, dir, cnt});
        };

        // Left edge [0, a0)
        if (m > 0) {
            long long len = a[0] - 0; // number of integer points 0..a0-1
            if (len > 0) {
                long long start_p = 0;
                long long start_val = a[0] - start_p; // = a[0]
                // Each step: p++, val--
                push_stream(start_p, start_val, +1, len);
            }
        } else {
            // No friends: every point's clearance is "infinite", but we can just fill 0..x
            // since any positions are optimal and valid.
            vector<long long> ans;
            for (long long p = 0; p <= x && (int)ans.size() < k; ++p) ans.push_back(p);
            for (int i = 0; i < k; ++i) {
                cout << ans[i] << (i + 1 == k ? '\n' : ' ');
            }
            continue;
        }

        // Internal gaps (a[i], a[i+1])
        for (int i = 0; i + 1 < m; ++i) {
            long long L = a[i], R = a[i+1];
            long long cnt_between = R - L - 1; // integer points strictly between
            if (cnt_between <= 0) continue;

            long long cl = (L + R) / 2;          // floor midpoint
            long long cr = (L + R + 1) / 2;      // ceil midpoint
            if ((R - L) % 2 == 0) {
                // Even gap length: one top at cl, then symmetric layers
                long long start_p_left = cl;
                long long start_val_left = cl - L;         // = (R-L)/2
                long long cnt_left = cl - L;               // positions L+1..cl
                push_stream(start_p_left, start_val_left, -1, cnt_left);

                // right stream starts at cl+1 with one less clearance
                long long start_p_right = cl + 1;
                long long start_val_right = R - start_p_right; // (R-L)/2 - 1
                long long cnt_right = R - (cl + 1);            // positions (cl+1)..(R-1)
                push_stream(start_p_right, start_val_right, +1, cnt_right);
            } else {
                // Odd gap length: two equal tops at cl and cr, then layers
                long long start_p_left = cl;
                long long start_val_left = cl - L; // floor((R-L)/2)
                long long cnt_left = cl - L;       // positions L+1..cl
                push_stream(start_p_left, start_val_left, -1, cnt_left);

                long long start_p_right = cr;
                long long start_val_right = R - cr; // floor((R-L)/2)
                long long cnt_right = R - cr;       // positions cr..R-1
                push_stream(start_p_right, start_val_right, +1, cnt_right);
            }
        }

        // Right edge (a_{m-1}, x]
        {
            long long len = x - a.back(); // number of integer points a_last+1 .. x
            if (len > 0) {
                long long start_p = x;
                long long start_val = start_p - a.back(); // = x - a_last
                // Each step: p--, val--
                push_stream(start_p, start_val, -1, len);
            }
        }

        vector<long long> ans;
        ans.reserve(k);
        unordered_set<long long> used;
        used.reserve(k * 2 + 16);

        // Pop top-k best non-friend positions (largest clearances)
        while ((int)ans.size() < k && !pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (!used.count(cur.p)) {
                ans.push_back(cur.p);
                used.insert(cur.p);
            }
            // advance stream
            cur.p += cur.dir;
            cur.val -= 1;
            cur.remaining -= 1;
            if (cur.remaining > 0 && cur.val > 0) {
                pq.push(cur);
            }
        }

        // If still need more, fill with friend positions (clearance 0)
        for (int i = 0; (int)ans.size() < k && i < m; ++i) {
            if (!used.count(a[i])) {
                ans.push_back(a[i]);
                used.insert(a[i]);
            }
        }

        // In the (theoretical) case we still need more (shouldn't happen with constraints),
        // we can scan neighbors near edges; but with k <= x+1 and adding friends, this suffices.

        for (int i = 0; i < k; ++i) {
            cout << ans[i] << (i + 1 == k ? '\n' : ' ');
        }
    }
    return 0;
}

