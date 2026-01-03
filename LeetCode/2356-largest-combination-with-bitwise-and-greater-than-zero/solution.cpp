bool bit_set(int n, int k) {
    return n & (1 << k);
}

class Solution {
public:
    int largestCombination(vector<int>& a) {
        // iterate through bits
        vector<int> bits(25, 0);
        for (int &i : a) {
            for (int j=0; j<25; j++) {
                if (bit_set(i, j)) {
                    bits[j]++;
                }
            }
        }
        int ans=0;
        for (int &i : bits) ans = max(ans, i);
        return ans;
    }
};
