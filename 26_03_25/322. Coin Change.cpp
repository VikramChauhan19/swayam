#include<vector>
using namespace std;
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