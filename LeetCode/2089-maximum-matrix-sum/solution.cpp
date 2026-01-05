class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negs = 0;
        int mn = 1e9;
        long long sum = 0;
        for (vector<int>& i : matrix) {
            for (int j : i) {
                sum += abs(j);
                mn = min(mn, abs(j));
                if (j < 0) negs++;
            }
        }

        if (negs % 2 != 0) sum -= 2 * mn;
        return sum;
    }
};
