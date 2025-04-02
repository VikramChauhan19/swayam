#include<vector>
using namespace std;
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n =nums.size();
            long long val = 0;
    
            int maxI = nums[0];
            long long mDiff = INT_MIN;
    
            for(int j = 1;j<n-1;j++){
                mDiff = max(mDiff,(long long)maxI-nums[j]);
                val = max(val,mDiff*nums[j+1]);
                maxI = max(maxI,nums[j]);
            }
            return val;
            
        }
    };