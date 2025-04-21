#include<vector>
#include<string>
using namespace std;
class Solution { //time = m*n time = m*n
    public:
        int n,m;
        bool solveR(string &s,string &p ,int i, int j,vector<vector<int>>&dp){
            if( j==n && i == m) return true;
            if( j == n) return false;
            
            if (i == m) {
                // Remaining characters in pattern must all be '*'
                while (j < n) {
                    if (p[j] != '*') return false;
                    j++;
                }
                return true;
            }
            if(dp[i][j] != -1) return dp[i][j];
    
            if(i<m && (s[i] == p[j] || p[j] == '?')){
                return dp[i][j] =  solveR(s,p,i+1,j+1,dp);
            }
            else if(p[j] == '*'){
                
                return dp[i][j] =  solveR(s,p,i+1,j,dp) || solveR(s,p,i,j+1,dp);
            }
            return dp[i][j] =  false;
        }
        bool isMatch(string s, string p) {
            m = s.size();
            n = p.size();
            vector<vector<int>>dp(m,vector<int>(n,-1));
            return solveR(s,p,0,0,dp);
            
        }
    };