#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
            int n = nums.size();
            vector<int>kIndex,ans;
            for(int i = 0;i<n;i++){
                if(nums[i] == key){
                    kIndex.push_back(i);
                }
            }
            int j = 0;
            for(int i = 0;i<n;i++){
                while(j<kIndex.size() && kIndex[j] < i-k){
                    j++;
                }
                if(j< kIndex.size() && abs(i-kIndex[j]) <= k ){
                    ans.push_back(i);
                }
            }
            return ans;       
        }
    };