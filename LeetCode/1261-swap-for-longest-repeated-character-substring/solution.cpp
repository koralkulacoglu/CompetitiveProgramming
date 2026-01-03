class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<pair<char, int>> sizes = {{text[0], 1}};
        for (int i=1; i<n; i++) {
            char curChar = text[i];
            char prevChar = sizes[sizes.size()-1].first;
            if (curChar == prevChar) sizes[sizes.size()-1].second++;
            else sizes.push_back({text[i], 1});
        }

        // for (auto i : sizes) cout << i.first << ':' << i.second << endl;

        /*
        at each step, we can connect sizes[i-1] and sizes[i+1] if sizes[i][1] = 1
        or we can add 1 to that if there's the right char after i+1 (keep a seen array going backwards)
        */
        vector<vector<bool>> seen(n+1, vector<bool>(26, false));
        seen[n-1][text[n-1]-'a'] = true;
        for (int i=n-2; i>=0; i--) {
            seen[i] = seen[i+1];
            seen[i][text[i]-'a'] = true;
        }

        // for (auto i : seen) {
        //     for (auto j : i) cout << j << ' ';
        //     cout << endl;
        // }

        if (sizes.size() == 1) return sizes[0].second;
        else if (sizes.size() == 2) return max(sizes[0].second, sizes[1].second);

        int ans = 0;
        int idx = sizes[0].second + sizes[1].second;
        int m = sizes.size();
        for (int i=1; i<m-1; i++) {
            int prevChar = sizes[i-1].first;
            int midChar = sizes[i].first;
            int nextChar = sizes[i+1].first;

            int prevSize = sizes[i-1].second;
            int midSize = sizes[i].second;
            int nextSize = sizes[i+1].second;

            idx += nextSize;

            ans = max(ans, prevSize);
            ans = max(ans, midSize);
            ans = max(ans, nextSize);

            // prev + 1
            bool charExistsAfterMid = seen[idx - nextSize][prevChar-'a'];
            ans = max(ans, prevSize + charExistsAfterMid);

            // prev + next
            if (midSize == 1 && prevChar == nextChar) {
                // cout << idx << ' ';
                bool charExistsAfterNext = seen[idx][prevChar-'a'];
                ans = max(ans, prevSize + nextSize + charExistsAfterNext);
            }
        }

        reverse(text.begin(), text.end());
        reverse(sizes.begin(), sizes.end());

        fill(seen.begin(), seen.end(), vector<bool>(26, false));

        // for (auto i : seen) {
        //     for (auto j : i) cout << j << ' ';
        //     cout << endl;
        // }

        seen[n-1][text[n-1]-'a'] = true;
        for (int i=n-2; i>=0; i--) {
            seen[i] = seen[i+1];
            seen[i][text[i]-'a'] = true;
        }

        idx = sizes[0].second + sizes[1].second;
        for (int i=1; i<m-1; i++) {
            int prevChar = sizes[i-1].first;
            int midChar = sizes[i].first;
            int nextChar = sizes[i+1].first;

            int prevSize = sizes[i-1].second;
            int midSize = sizes[i].second;
            int nextSize = sizes[i+1].second;

            idx += nextSize;

            ans = max(ans, prevSize);
            ans = max(ans, midSize);
            ans = max(ans, nextSize);

            // prev + 1
            bool charExistsAfterMid = seen[idx - nextSize][prevChar-'a'];
            ans = max(ans, prevSize + charExistsAfterMid);

            // prev + next
            if (midSize == 1 && prevChar == nextChar) {
                // cout << idx << ' ';
                bool charExistsAfterNext = seen[idx][prevChar-'a'];
                ans = max(ans, prevSize + nextSize + charExistsAfterNext);
            }
        }

        return ans;
    }
};
