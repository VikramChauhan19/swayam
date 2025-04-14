#include<vector>
using namespace std;
class Solution {
    public:
        int uniquePaths(int m, int n) { //space = O(N^2) time = O(N^2)
            vector<vector<int>>dp(m+1,vector<int>(n+1,0));
            dp[m-1][n-1] = 1;
            for(int i = 0;i<m;i++){
                dp[i][n-1] = 1;
            }
            for(int i = m-1;i>=0;i--){
                for(int j = n-2;j>=0;j--){
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
            return dp[0][0];       
        }
    };