class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool wk = false;
        for (vector<int> triangle : triplets) {
            if (triangle[1] > target[1]) continue;
            if (triangle[2] > target[2]) continue;
            if (triangle[0] == target[0]) {
                wk = true;
                break;
            }
        }
        if (!wk) return false;

        wk = false;
        for (vector<int> triangle : triplets) {
            if (triangle[0] > target[0]) continue;
            if (triangle[2] > target[2]) continue;
            if (triangle[1] == target[1]) {
                wk = true;
                break;
            }
        }
        if (!wk) return false;

        wk = false;
        for (vector<int> triangle : triplets) {
            if (triangle[0] > target[0]) continue;
            if (triangle[1] > target[1]) continue;
            if (triangle[2] == target[2]) {
                wk = true;
                break;
            }
        }

        return wk;
    }
};
