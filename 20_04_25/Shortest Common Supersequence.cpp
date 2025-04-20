#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
      int m,n;
      int solveR(string &s1, string &s2,int i,int j,vector<vector<int>>&dp){
          if(i>=m) return n-j;
          if(j>=n) return m-i;
          if(dp[i][j] != -1) return dp[i][j];
          if(s1[i] == s2[j]) return dp[i][j] =  1+solveR(s1,s2,i+1,j+1,dp);
          else {
              return dp[i][j] = 1+ min(solveR(s1,s2,i+1,j,dp),solveR(s1,s2,i,j+1,dp));
          }
      }
      // Function to find length of shortest common supersequence of two strings.
      int shortestCommonSupersequence(string &s1, string &s2) {
          // code here
          m = s1.size();
          n = s2.size();
          vector<vector<int>>dp(m,vector<int>(n,-1));
          return solveR(s1,s2,0,0,dp);
      }
  };
  