#include<vector>
using namespace std;
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) { //space = m*n time = m*n 
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
            
            for(int i = m-1;i>=0;i--){
                for(int j = n-1;j>=0;j--){
                    if(i == m-1 && j == n-1) dp[i][j] = grid[m-1][n-1];
                    else{
                        dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
                    }
                }
            }
            return dp[0][0];
            
        }
    };