class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> height(m, 0);
        int res = 0;

        for (int i = 0; i < n; i++) {
            // update histogram heights
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j]++;
            }

            // monotonic stack: compute # of submatrices ending at row i
            stack<int> st;
            vector<int> dp(m, 0);
            for (int j = 0; j < m; j++) {
                while (!st.empty() && height[st.top()] >= height[j]) {
                    st.pop();
                }

                if (!st.empty()) {
                    int prev = st.top();
                    dp[j] = dp[prev] + height[j] * (j - prev);
                } else {
                    dp[j] = height[j] * (j + 1);
                }

                res += dp[j];
                st.push(j);
            }
        }
        return res;
    }
};

