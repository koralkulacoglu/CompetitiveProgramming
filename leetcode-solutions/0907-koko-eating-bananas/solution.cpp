class Solution {
public:
    bool check(int k, vector<int>& a, int h) {
        if (k == 0) return false;
        for (int i : a) {
            h -= (i+k-1) / k;
            if (h < 0) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1, right=1e9;
        while (left <= right) {
            int k = (left + right)/2;
            if (check(k, piles, h)) {
                if (!check(k-1, piles, h)) return k;
                right = k-1;
            }
            else {
                left = k+1;
            }
        }
        return -1;
    }
};
