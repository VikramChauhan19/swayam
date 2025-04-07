#include<vector>
#include<numeric>
using namespace std;
class Solution {
    public:
        int n;
    
        bool solveM(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
            if(i>=n) return false;
            if(target<0) return false;
            if(target==0) return true;
    
            if(dp[i][target] != -1) return dp[i][target];
            bool inc = solveM(i+1,nums,target-nums[i],dp);
            bool exc = solveM(i+1,nums,target,dp);
    
            return dp[i][target] = inc||exc;
        }
        bool canPartition(vector<int>& nums) {
            n = nums.size();
            int target = accumulate(nums.begin(),nums.end(),0);
            if(target%2 == 0){
                target = target/2;
            }
            else return false;
            vector<vector<int>>dp(n,vector<int>(target+1,-1));
            return solveM(0,nums,target,dp);
            
        }
    };