class Solution {
public:
    bool isInside(int xA, int yA, int xB, int yB, int xC, int yC) {
        return xA <= xC && xC <= xB && yB <= yC && yC <= yA;
    }

    bool isGood(vector<vector<int>>& points, int xA, int yA, int xB, int yB) {
        for (vector<int>& C : points) {
            int xC = C[0];
            int yC = C[1];
            if (xC == xA && yC == yA) continue;
            if (xC == xB && yC == yB) continue;
            if (isInside(xA, yA, xB, yB, xC, yC)) return false;
        }
        return true;
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (vector<int>& A : points) {
            int xA = A[0];
            int yA = A[1];
            for (vector<int>& B : points) {
                int xB = B[0];
                int yB = B[1];
                if ((xA == xB && yA == yB) || xA > xB || yA < yB) continue;
                ans += isGood(points, xA, yA, xB, yB);
            }
        }
        return ans;
    }
};
