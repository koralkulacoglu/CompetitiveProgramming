class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int flips = 0;
        queue<int> indices;
        for (int i=0; i<n; i++) {
            while (!indices.empty() && i > indices.front()) {
                indices.pop();
                flips--;
            }

            if ((nums[i] & 1) == (flips & 1)) {
                if (i + k > n) return -1;
                
                indices.push(i + k - 1);
                flips++;
                ans++;
            }
        }

        return ans;
    }
};
