class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int idx = 0;
        vector<int> psa(2e5+2, 0);
        for (int i=1; i<=2e5+1; i++) {
            psa[i] = psa[i-1];
            if (idx < n && i-1 == fruits[idx][0]) {
                psa[i] += fruits[idx][1];
                idx++;
            }
        }

        int ans = 0;
        // move k steps to the right
        for (int right=k; right>=0; right--) {
            int rightIdx = min((int)2e5+1, startPos + right + 1);

            /*
            calculate how many we can move to the left
            if we move right by i, then we have to move left by i also. so we move can move left = k - 2*right
            */
            int left = max(0, k - 2*right);
            int leftIdx = max(0, startPos - left);

            int curAns = psa[rightIdx] - psa[leftIdx];

            ans = max(ans, curAns);
        }

        // move k steps to the left
        for (int left=k; left>=0; left--) {
            int leftIdx = max(0, startPos - left);

            int right = max(0, k - 2*left);
            int rightIdx = min((int)2e5+1, startPos + right + 1);

            int curAns = psa[rightIdx] - psa[leftIdx];

            ans = max(ans, curAns);
        }

        // for (int i=0; i<20; i++) cout << psa[i] << ' ';
        // cout << endl;

        return ans;
    }
};
