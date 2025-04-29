#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            int maxE = *max_element(nums.begin(),nums.end());
            int i = 0;
            int count = 0;
            long long ans = 0;
            for(int j = 0;j<n;j++){
                if(nums[j] == maxE) count++;
                if(count == k){
                    ans += (n-j);
                    while(count == k){
                        if(nums[i] == maxE) count--;
                        i++;
                        if(count == k) ans += (n-j);
                    }
                }
            }
            return ans;
            
        }
    };