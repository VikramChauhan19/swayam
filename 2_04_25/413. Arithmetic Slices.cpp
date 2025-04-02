#include<vector>
using namespace std;
class Solution {
    public:
        
        int numberOfArithmeticSlices(vector<int>& nums) {
            int sum = 0;
            vector<int>dp(nums.size());
            for(int i = 2;i<nums.size();i++){
                if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                    dp[i] = 1+dp[i-1];
                    sum += dp[i];
                }
            }
            return sum;
            
            
        }
    };