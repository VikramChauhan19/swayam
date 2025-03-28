#include<vector>
using namespace std;
class Solution {
    public:
        void nextPermutation(vector<int>& nums) { //Tc -> o(n)
                                                //SC-> O(1)
            int n = nums.size();
            int i = n - 2;
    
            
            while(i >= 0 && nums[i] >= nums[i + 1]) i--; //O(n)
    
            if(i >= 0) { 
                
                int j = n - 1;
                while(nums[j] <= nums[i]) j--; //O(n)
    
                
                swap(nums[i], nums[j]);
            }
    
            
            reverse(nums.begin() + i + 1, nums.end()); //0(n)
        }
    };
    