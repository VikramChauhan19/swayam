#include<vector>
using namespace std;
class Solution {
    public:
      int n = 0;
      int solve(vector<int>&arr,int target,int i,vector<vector<int>>&dp){
          if(i == n) return target == 0?1:0;;
          if(i>=n) return 0;
          if(dp[i][target] != -1) return dp[i][target];
          int skip = solve(arr,target,i+1,dp);
          int take = 0;
          if(target>=arr[i]){
              take = solve(arr,target-arr[i],i+1,dp);
          }
          return dp[i][target] = take + skip;
      }
      int perfectSum(vector<int>& arr, int target) {
           n = arr.size();
           vector<vector<int>>dp(n,vector<int>(target+1,-1));
           return solve(arr,target,0,dp);
      }
  };