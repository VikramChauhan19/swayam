#include<vector>
using namespace std;

//SOL ->1 Memoization
class Solution {
    public:
        int memo(vector<int>&coins,int amount,vector<int>&dp){
            if(amount == 0) return 0;
            if(amount < 0) return INT_MAX;
            if(dp[amount] != -1) return dp[amount];
            int minC = INT_MAX;
            for(int i = 0;i<coins.size();i++){   // -> N
                int result = memo(coins,amount-coins[i],dp);  // amount (becouse of dp)
                if(result != INT_MAX){
                    minC = min(minC,1+ result);
                }
            }
            dp[amount] = minC;     //TC = O(N × amount)
            return dp[amount];
        }
        int coinChange(vector<int>& coins, int amount) {
            vector<int>dp(amount+1,-1); // space  = amount
            int result = memo(coins,amount,dp);     //SC -> 0(amount)
            return result == INT_MAX ? -1 : result;      
        }
    };

//soln - 2 Tabular
class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {    //TC = )(amount*n)
            vector<int>dp(amount+1,INT_MAX);  //SC -> )(amount)
            dp[0] = 0;
            for(int i = 1;i<=amount;i++){    //-> amount
                for(int j = 0;j<coins.size();j++){ // ->n times    
                    
                    if(i-coins[j] >=0 && dp[i-coins[j]] != INT_MAX){
                        dp[i] = min(dp[i], 1+ dp[i-coins[j]]);
                    }
                }
            }
            return dp[amount] == INT_MAX? -1:dp[amount];
        }
    };