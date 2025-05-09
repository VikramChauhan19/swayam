#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {//TC = nlogn +n*n*n-> O(n*n*n)
            int n = nums.size();
            vector<vector<int>> ans; //sc->O(N)
            
            if (n < 4) return ans; 
            sort(nums.begin(), nums.end()); // n*logn
    
            for (int i = 0; i < n - 3; i++) {
                if (i > 0 && nums[i] == nums[i - 1]) continue; // n
                
                for (int j = i + 1; j < n - 2; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue; // n
                    
                    int k = j + 1, l = n - 1;
    
                    while (k < l) {    //n
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l]; 
    
                        if (sum == target) {
                            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
    
                            
                            while (k < l && nums[k] == nums[k + 1]) k++;
                            
                            while (k < l && nums[l] == nums[l - 1]) l--;
    
                            k++; 
                            l--; 
                        } 
                        else if (sum < target) {
                            k++; 
                        } 
                        else {
                            l--; 
                        }
                    }
                }
            }
            
            return ans;
        }
    };
    