class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        auto goUp = [&](double y) {
            double above=0, below=0;
            for (vector<int>& square : squares) {
                double yi = square[1], li = square[2];
                double h_below = min(li, max(0.0, y - yi));
                below += h_below * li;
                above += (li - h_below) * li;
            }
            return above > below;
        };

        double l=0, r=2e9;
        while (r - l > 1e-5) {
            double m = l + (r - l) / 2;
            if (goUp(m)) l = m;
            else r = m;
        }

        return r;
    }
};
