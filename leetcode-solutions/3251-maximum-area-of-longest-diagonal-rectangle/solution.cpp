class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        double diagonal = 0;
        for (vector<int>& i : dimensions) {
            int l = i[0];
            int w = i[1];
            double d = sqrt(l*l + w*w);
            int a = l*w;

            if (d > diagonal) {
                diagonal = d;
                area = a;
            }
            else if (d == diagonal) {
                area = max(area, a);
            }
        }

        return area;
    }
};
