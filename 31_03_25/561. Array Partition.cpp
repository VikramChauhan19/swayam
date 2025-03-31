#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int arrayPairSum(vector<int>& nums) { //TC-> O(nlogn) SC= O(1)
            int n = nums.size();
            sort(nums.begin(),nums.end()); //time->O(nlogn)
            int ans = 0;
            for(int i = 0;i<n;i=i+2){ //time- O(n/2)
                ans+= nums[i];
            }
            return ans;
    
            
        }
    };