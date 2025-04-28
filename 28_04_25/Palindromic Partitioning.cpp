#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
      int solve(string &s, int i, int j, vector<vector<int>> &dp, vector<vector<bool>> &isPal) {
          if (i >= j) return 0;
          if (isPal[i][j]) return 0;
          if (dp[i][j] != -1) return dp[i][j];
  
          int ans = INT_MAX;
          for (int k = i; k < j; k++) {
              if (isPal[i][k]) {  
                  int right = solve(s, k + 1, j, dp, isPal);
                  ans = min(ans, 1 + right);
              }
          }
          return dp[i][j] = ans;
      }
  
      int palPartition(string &s) {
          int n = s.size();
          vector<vector<int>> dp(n, vector<int>(n, -1));
          vector<vector<bool>> isPal(n, vector<bool>(n, false));
  
          
          for (int i = 0; i < n; i++) {
              isPal[i][i] = true; 
          }
          for (int i = 0; i < n - 1; i++) {
              isPal[i][i + 1] = (s[i] == s[i + 1]);
          }
          for (int len = 3; len <= n; len++) {
              for (int i = 0; i <= n - len; i++) {
                  int j = i + len - 1;
                  isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
              }
          }
  
          return solve(s, 0, n - 1, dp, isPal);
      }
  };
  