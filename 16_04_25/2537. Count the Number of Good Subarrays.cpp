#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {//time = O(n) //space = o(n)
            int n = nums.size();
            int i = 0;
            int j = 0;
            unordered_map<int,int>m;
            long long result = 0;
            long long pair = 0;
            while(j<n){
                pair += m[nums[j]];
                m[nums[j]]++;
    
                while(pair>=k){
                    result += n-j;
                    m[nums[i]]--;
                    pair -= m[nums[i]];
                    i++;
                }
                j++;
            }
            return result;
            
        }
    };