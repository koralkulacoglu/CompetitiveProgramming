#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

      

        // General case for grids larger than 1x1
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int currOne = grid[i][j] + grid[i][m - j - 1] + grid[n - 1 - i][j] + grid[n - 1 - i][m - j - 1];
                if (currOne == 1 || currOne == 3) {
                    count++;
                } else if (currOne == 2) {
                    count += 2;
                }
            }
        }

        if(n%2==0 && m%2==0) return count;
        int palinOnes=0;
        int onechange=0;
        if(m%2==1){
            for(int i=0;i<n/2;i++){
                if(grid[i][m/2]==1 && grid[n-i-1][m/2]==1) palinOnes++;
                if(grid[i][m/2]!= grid[n-i-1][m/2]){
                    count++;
                    onechange++;
                }
            }
        }
        if(n%2==1){
            for(int i=0;i<m/2;i++){
                if(grid[n/2][i]==1 && grid[n/2][m-i-1]==1) palinOnes++;
                if(grid[n/2][i]!= grid[n/2][m-i-1]){
                    count++;
                    onechange++;
                }
            }
        }
        if(palinOnes%2==1){
            if(onechange==0) count+=2;
        }
        if(n%2==1 && m%2==1 && grid[n/2][m/2]==1) count++;
        return count;
    }
};
