//Tabulation
#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {// space = m*n time = m*n
            int m = text1.size();
            int n = text2.size();
            vector<vector<int>>dp(m+1,vector<int>(n+1,0));
            for(int i = m-1;i>=0;i--){
                for(int j = n-1;j>=0;j--){
                    if(text1[i] == text2[j]){
                        dp[i][j] = 1+dp[i+1][j+1];
                    }
                    else{
                        dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                    }
                }
            }
            return dp[0][0];
        }
    };

    /* Memoization
    class Solution {
public:
    int m,n;
    int dp[1001][1001];

    int solveR(string text1,string text2,int i,int j){
        if(i>=m) return 0;
        if(j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]){
            return dp[i][j] =  1+solveR(text1,text2,i+1,j+1);
        }
        else return dp[i][j] =  max(solveR(text1,text2,i+1,j),solveR(text1,text2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size();
        n = text2.size();\
        memset(dp,-1,sizeof(dp));
        
        return solveR(text1,text2,0,0);        
    }
};
    */