class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char current = board[i][j];
                if (current == '.') continue;
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (rows[i].count(current) || cols[j].count(current) || boxes[boxIndex].count(current)) {
                    return false; // Duplicate found, invalid Sudoku
                }
                
                rows[i].insert(current);
                cols[j].insert(current);
                boxes[boxIndex].insert(current);
            }
        }
        
        return true;
    }
};

