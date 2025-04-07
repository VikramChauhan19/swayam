#include<vector>
using namespace std;
class Solution {
    public:
      int n;
      bool solve(vector<int>&arr,int sum,int i,vector<vector<int>>&dp){
          if(sum == 0) return true;
          if(i>=n) return false;
          if(sum<0) return false;
          if(dp[i][sum] != -1) return dp[i][sum];
          bool inc = solve(arr,sum-arr[i],i+1,dp);
          bool exc = solve(arr,sum,i+1,dp);
          return dp[i][sum]  = inc||exc;
          
      }
      bool isSubsetSum(vector<int>& arr, int sum) {
          n = arr.size();
          vector<vector<int>>dp(n,vector<int>(sum+1,-1));
          return solve(arr,sum,0,dp);
          
      }
  };
  