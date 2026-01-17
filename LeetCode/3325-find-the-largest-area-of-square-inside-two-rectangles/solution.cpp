class Solution {
    long long intersection(vector<int>& bottomLeft1, vector<int>& topRight1, vector<int>& bottomLeft2, vector<int>& topRight2) {
        int x1 = max(bottomLeft1[0], bottomLeft2[0]);
        int y1 = max(bottomLeft1[1], bottomLeft2[1]);
        
        int x2 = min(topRight1[0], topRight2[0]);
        int y2 = min(topRight1[1], topRight2[1]);

        long long length = max(0, x2 - x1);
        long long height = max(0, y2 - y1);
        
        long long side = min(length, height);

        return side * side;
    }

public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                ans = max(ans, intersection(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]));
            }
        }

        return ans;
    }
};
