#include<vector>
using namespace std;
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { //space = O(N^2) time = O(N^2)
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
    
            if (obstacleGrid[m-1][n-1] == 1) return 0;
    
            vector<vector<long long>> dp(m, vector<long long>(n, 0));
    
            // Fill last column
            for (int i = m - 1; i >= 0; --i) {
                if (obstacleGrid[i][n - 1] == 0)
                    dp[i][n - 1] = 1;
                else
                    break; // stop marking cells after an obstacle
            }
    
            // Fill last row
            for (int j = n - 1; j >= 0; --j) {
                if (obstacleGrid[m - 1][j] == 0)
                    dp[m - 1][j] = 1;
                else
                    break;
            }
    
            // Fill the rest of the grid
            for (int i = m - 2; i >= 0; --i) {
                for (int j = n - 2; j >= 0; --j) {
                    if (obstacleGrid[i][j] == 0) {
                        dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
    
            return dp[0][0];
        }
    };