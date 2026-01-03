// length of the shortest sequence of rolls that cannot be taken from rolls
// we need to have every number followed by every number answer times
// check how many times each number follows everything starting from the end

// [4,2,1,2,3,3,2,4,1]
// 4 is followed
// 2 is followed
// 1 is followed
// 3 is followed


class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n=rolls.size(), ans=1;
        set<int> vals;
        for (int i=n-1; i>=0; i--) {
            int cur = rolls[i];
            vals.insert(cur);
            if (vals.size() == k) {
                vals.clear();
                ans++;
            }
        }
        return ans;
    }
};
