#include<vector>
using namespace std;
class Solution {
    public:
        int n = 0;
        int solveR(int amount,vector<int>&coins,int i,vector<vector<int>>&dp){
            if(amount == 0) return 1;
            if(amount<0) return 0;
            if(dp[i][amount] != -1) return dp[i][amount];
           
            int count = 0;
            for(int j = i;j<n;j++){
                count+= solveR(amount-coins[j],coins,j,dp);
            }
            return dp[i][amount] = count;
        }
        int change(int amount, vector<int>& coins) {
            n = coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,-1));
            return solveR(amount,coins,0,dp);
        }
    };