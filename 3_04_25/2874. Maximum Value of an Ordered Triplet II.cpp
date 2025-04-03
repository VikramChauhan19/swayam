#include<vector>
using namespace std;
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            int maxI = nums[0];
            long long mval= 0;
            int maxD = 0;
            for(int j = 1;j<n-1;j++){ //TC= O(N) sc = O(1)
                int  diff = maxI-nums[j];
                int maxD = max(diff,maxD);
                mval = max(mval,(long long)maxD*nums[j+1]);
                maxI = max(maxI,nums[j]);
    
            }
            return mval;
            
        }
    };