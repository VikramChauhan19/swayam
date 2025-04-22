#include<vector>
using namespace std;
class Solution {
    public: //space = n*n time = n*n
      int solve(vector<int>&arr,int i, int j,vector<vector<int>>&dp){
          if(i>=j) return 0;
          int ans = INT_MAX;
          if(dp[i][j] != -1) return dp[i][j];
          
          for(int k = i;k<=j-1;k++){
              int temp = solve(arr,i,k,dp)
              + solve(arr,k+1,j,dp)
              +arr[i-1]*arr[k]*arr[j];
              ans = min(ans,temp);
          }
          return dp[i][j] = ans;
      }
      int matrixMultiplication(vector<int> &arr) {
          int n = arr.size();
          // code here
          vector<vector<int>>dp(n,vector<int>(n,-1));
          return solve(arr,1,n-1,dp);
      }
  };