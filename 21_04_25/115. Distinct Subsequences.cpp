#include<vector>
#include<string>
using namespace std;
class Solution { //time = m*n space = m*n
    public:
        int m, n;
        int solveR(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
            if (j == n) return 1;         // Fully matched t
            if (i == m) return 0;         // Reached end of s without matching all of t
    
            if (dp[i][j] != -1) return dp[i][j];
    
            int pick = 0;
            if (s[i] == t[j]) {
                pick = solveR(s, t, i + 1, j + 1, dp);  // Match current char
            }
            int skip = solveR(s, t, i + 1, j, dp);      // Skip current s[i]
    
            return dp[i][j] = pick + skip;
        } 
        int numDistinct(string s, string t) {
            m = s.size();
            n = t.size();
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return solveR(s, t, 0, 0, dp);
        }
    };
    