#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& nums) { //tc= O(N*N) sc= O(N*N)
            int n = nums.size();
            vector<unordered_map<long,int>>mp(n); //space = O(N*N)
            int result = 0;
    
            for(int i = 0;i<n;i++){ //time = O(n*n)
                for(int j = 0;j<i;j++){
                    long diff = (long)nums[i]-nums[j];
                    auto it = mp[j].find(diff);
                    int count_at_j = it == mp[j].end()?0:it->second;
                    mp[i][diff] += count_at_j + 1;
                    result += count_at_j;
    
                }
            }
            return result;
        }
    };