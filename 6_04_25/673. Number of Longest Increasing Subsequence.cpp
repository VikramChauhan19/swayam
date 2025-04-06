#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int findNumberOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int>dp(n,1);
            vector<int>count(n,1);
    
            for(int i = 1;i<n;i++){
                for(int j = 0;j<i;j++){
                    if(nums[i]>nums[j]){
                        if(dp[i] == dp[j] + 1)
                            count[i] += count[j];
                        else if(dp[i] < dp[j] + 1){
                            dp[i] = dp[j] + 1;
                            count[i] = count[j];
                        }
                    }
                    
                }
            }
            int maxVal = *max_element(begin(dp), end(dp));
            int result = 0;
            for(int i = 0; i<n; i++) {
                if(dp[i] == maxVal) {
                    result += count[i];
                }
            }
            
            return result;     
        }
    };