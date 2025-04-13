#include<vector>
using namespace std;
class Solution {
    public:
     int solveR(vector<int>&price,int n,int l,vector<int>&dp){
       if(l <= 0) return 0;
       if(dp[l] != -1) return dp[l];
       int res= INT_MIN;
       for(int i = 1;i<=n;i++){
         res  = max(res,price[i-1] + solveR(price,n,l-i,dp));        
       }
        return dp[l] = res;
     }
     int rodCutting(vector<int> price, int n) {
       vector<int>dp(n+1,-1);
       return solveR(price,n,n,dp);
     }
 };