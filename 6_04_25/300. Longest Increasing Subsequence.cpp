#include<vector>
using namespace std;
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int>dp(n,1); //sp = O(N*N)
            int res = 1;
            
            for(int i = 1;i<n;i++){ //time= O(N*N)
                for(int j = 0;j<i;j++){
                    if(nums[i]>nums[j]){
                        if(dp[i]<dp[j]+1){
                            dp[i] = dp[j] +1;
                            res = max(res,dp[i]);
                        }
                    }
                }
            }
            return res;
            
        }
    };