#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        /*
        void countingSort(vector<int>&nums){ //tc = O(N) sc = O(N)
            int maxE = *max_element(nums.begin(),nums.end());
            //since 1 <= nums[i] <= 109
            //so we cannot use counting sort as it will take too much space
            
            vector<int>freq(maxE+1,0);
            for(auto i:nums){
                freq[i]++;
            }
            int index = 0;
            for(int i= 0;i<=maxE;i++){
                while(freq[i]>0){
                    nums[index++] = i;
                    freq[i]--;
                }
            }
        }*/
        int findValueOfPartition(vector<int>& nums) { // tc = O(N) SC = O(n)
            sort(nums.begin(),nums.end());
            int n = nums.size();
            int ans = INT_MAX;
            for(int i = 0;i<n-1;i++){ //O(n-1)
                ans = min(ans,abs(nums[i] - nums[i+1]));
            }
            return ans;    
            
        }
    };