#include<vector>
#include<string>
using namespace std;
class Solution { //time = O(n*m) space = O(n*m)
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size();
            int n = word2.size();
            vector<vector<int>>dp(m+1,vector<int>(n+1,0));
            for (int i = 0; i <= m; i++) dp[i][n] = m - i; // when word2 is empty
            for (int j = 0; j <= n; j++) dp[m][j] = n - j; // when word1 is empty
    
    
            for(int i = m-1;i>=0;i--){
                for(int j = n-1;j>=0;j--){
                    if(word1[i] == word2[j]){
                        dp[i][j] =  dp[i+1][j+1];
                    }
                    else{
                        dp[i][j] =  1+ min(dp[i+1][j],min(dp[i+1][j+1], dp[i][j+1]));
                    }
                }
            }
            return dp[0][0];
            
        }
    };