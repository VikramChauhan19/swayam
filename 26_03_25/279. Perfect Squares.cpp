#include<vector>
using namespace std;
class Solution {
    public:
        /*int helper(int n){
            if(n==0) return 0;
            int minC = INT_MAX;
            for(int i = 1;i*i<=n;i++){
                int result = 1 + helper(n-i*i);
                minC = min(minC,result); 
            }
            return minC;
        }*/
        int memo(vector<int>&dp,int n){
            if(n == 0) return 0;
            if(dp[n] != -1) return dp[n];
            int minC = INT_MAX;
            for(int i = 1;i*i<= n;i++){
                int result = 1+memo(dp,n-i*i);
                minC = min(result,minC);
            }
            dp[n] = minC;
            return dp[n];      
        }
        int numSquares(int n) {
            vector<int>dp(n+1,-1);
            return memo(dp,n);
            //return helper(n);       
        }
    };

    // Tabular
    class Solution {
        public:
            int numSquares(int n) {
                vector<int>ans(n+1,INT_MAX);
                ans[0] = 0;
                for(int i = 1;i<=n;i++){
                    for(int j = 1;j*j<=i;j++){
                        ans[i] = min(ans[i],1+ans[i-j*j]);
                    }
                }
                return ans[n];
        
                
            }
        };