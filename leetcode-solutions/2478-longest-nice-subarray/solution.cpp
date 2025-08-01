class Solution {
public:
    vector<int> bitFreq;

    bool checkAnd(int x) {
        for (int i = 31; i >= 0; --i) {
            if (x & (1 << i) && bitFreq[i]) return true;
        }
        return false;
    }

    void removeBits(int x) {
        for (int i = 31; i >= 0; --i) {
            if (x & (1 << i)) bitFreq[i] = max(0, bitFreq[i] - 1);
        }
    }

    void addBits(int x) {
        for (int i = 31; i >= 0; --i) {
            if (x & (1 << i)) bitFreq[i]++;
        }
    }

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        bitFreq.assign(32, 0);

        int ans = 0;
        int left = 0;
        for (int right=0; right<n; right++) {
            int curRight = nums[right];

            while (checkAnd(curRight)) {
                int curLeft = nums[left];

                removeBits(curLeft);

                left++;
            }

            addBits(curRight);

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
