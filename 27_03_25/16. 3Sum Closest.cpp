#include <iostream>
#include <vector>
#include <algorithm> // For sorting
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) { //TC = nlogn + n*n -> O(n*n)
        int n = nums.size();                            //sc = O(1);
        sort(nums.begin(), nums.end());  // O(nlogn)
        int closest = nums[0] + nums[1] + nums[2]; 

        for (int i = 0; i < n - 2; i++) { //O(n)       ->O(n*n)
            int j = i + 1, k = n - 1;
            
            while (j < k) { //O(n)
                int sum = nums[i] + nums[j] + nums[k];

              
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum < target) {
                    j++; 
                } else {
                    k--; 
                }
            }
        }

        return closest;
    }
};