#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int>s(nums.begin(),nums.end());
            unordered_map<int,int>m;
            int uniq = s.size();
    
            int i = 0;
            int j = 0;
            int res= 0;
            int count = 0;
    
            while(j<n){
                m[nums[j]]++;
                while(m.size() == uniq){
                    res += (n-j);
                    m[nums[i]]--;
                    if(m[nums[i]] == 0) m.erase(nums[i]);
                    i++;
                }
                j++;
    
            }
            return res;
            
        }
    };