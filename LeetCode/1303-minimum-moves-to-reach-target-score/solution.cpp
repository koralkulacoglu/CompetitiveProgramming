class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (target > 1 && maxDoubles) {
            if (target & 1) target--;
            else {
                target >>= 1;
                maxDoubles--;
            }
            ans++;
        }
        return ans + target - 1;
    }
};
