#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int minPairSum(vector<int>& nums) { //TC = O(nlogn) SC = O(1)
            int n = nums.size(); 
            sort(nums.begin(),nums.end()); // time = nlogn
            int  ans = 0;
            for(int i = 0;i<n/2;i++){
                ans = max(ans,nums[i]+nums[n-1-i]);
            }
            return ans;
            
        }
    };
    
    //optimize soln(counting sort) TC = O(N)  SC = O(N);
    /*
    class Solution {
    public:
        int minPairSum(vector<int>& nums) {
            int maxVal = *max_element(nums.begin(), nums.end());
            vector<int> count(maxVal + 1, 0);
    
            // Step 1: Count occurrences
            for (int num : nums) {
                count[num]++;
            }
    
            // Step 2: Reconstruct the sorted array
            vector<int> sortedNums;
            for (int i = 0; i <= maxVal; i++) {
                while (count[i] > 0) {
                    sortedNums.push_back(i);
                    count[i]--;
                }
            }
    
            // Step 3: Compute minPairSum
            int n = sortedNums.size();
            int ans = 0;
            for (int i = 0; i < n / 2; i++) {
                ans = max(ans, sortedNums[i] + sortedNums[n - 1 - i]);
            }
    
            return ans;
        }
    };
    */