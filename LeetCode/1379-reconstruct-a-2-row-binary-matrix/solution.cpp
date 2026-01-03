class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> matrix(2, vector<int>(n, -1));

        for (int i=0; i<n; i++) {
            if (colsum[i] == 2) {
                matrix[0][i] = 1;
                matrix[1][i] = 1;
                upper--;
                lower--;
            }
            else if (colsum[i] == 0) {
                matrix[0][i] = 0;
                matrix[1][i] = 0;
            }
        }

        for (int i=0; i<n; i++) {
            if (matrix[0][i] == -1) {
                if (upper > 0) {
                    matrix[0][i] = 1;
                    matrix[1][i] = 0;
                    upper--;
                }
                else {
                    matrix[0][i] = 0;
                    matrix[1][i] = 1;
                    lower--;
                }
            }
        }

        if (upper != 0 || lower != 0) return {};

        return matrix;
    }
};
