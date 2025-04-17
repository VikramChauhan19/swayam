#include<vector>
using namespace std;
class Solution {
    public:
        int m;
        int solveR(vector<vector<int>>&triangle,int r,int c,vector<vector<int>>&dp){
            if(r >= m) return 0;
            if(dp[r][c] != -1) return dp[r][c];
            int op1 = solveR(triangle,r+1,c,dp);
            int op2 = solveR(triangle,r+1,c+1,dp);
            return dp[r][c] = triangle[r][c] + min(op1, op2);
        }
        int minimumTotal(vector<vector<int>>& triangle) {// time = m*m space = m
            m = triangle.size();
            vector<vector<int>>dp(m,vector<int>(m,-1));
            return solveR(triangle,0,0,dp);
                   
        }
    };