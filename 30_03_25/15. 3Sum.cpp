#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) { //TC-> o(n*n)
            int n  = nums.size();
            vector<vector<int>>ans;
            sort(nums.begin(),nums.end());
    
            for(int i = 0;i<n;i++){
                int j = i+1;
                int k = n-1;
                int target = -nums[i];
    
                while(j<k){
                    int sum = nums[j] + nums[k];
                    if(sum>target){
                        k--;                  
    
                    }
                    else if(sum<target){
                        j++;
                    }
                    else{
                         vector<int> triplet = {nums[i], nums[j], nums[k]};
                         ans.push_back(triplet);
                    
                   
                        while (j < k && nums[j] == triplet[1]) j++;
    
                    
                        while (j < k && nums[k] == triplet[2]) k--;
                    }
    
                }
                while(i<n-2 && nums[i] == nums[i+1]) i++;
            }
            return ans;
            
        }
    };