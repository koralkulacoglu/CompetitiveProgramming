class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = hBars.size();
        int v = vBars.size();

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxHeight = 2;
        for (int i=0; i<h; i++) {
            for (int j=i+1; j<h; j++) {
                if (hBars[j] != hBars[j-1] + 1) break;
                maxHeight = max(maxHeight, j - i + 2);
            }
        }

        int maxWidth = 2;
        for (int i=0; i<v; i++) {
            for (int j=i+1; j<v; j++) {
                if (vBars[j] != vBars[j-1] + 1) break;
                maxWidth = max(maxWidth, j - i + 2);
            }
        }

        int length = min(maxHeight, maxWidth);

        return length * length;
    }
};
