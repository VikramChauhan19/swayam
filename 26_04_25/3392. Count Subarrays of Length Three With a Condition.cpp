#include<vector>
using namespace std;
class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size();
            if(n<3) return 0;
            int ans = 0;
            for(int i = 2; i<n; i++){
                if(nums[i-1]%2 !=0) continue;
                if(nums[i] + nums[i-2] == nums[i-1]/2){
                    ans += 1;
                }        
            }
            return ans;       
        }
    };