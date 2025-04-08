#include<vector>
using namespace std;
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {//time = O(N) space = O(101)
            int n = nums.size();
            vector<int>frq(101,0);
            for(int i = n-1;i>=0;i--){
                frq[nums[i]]++;
                if(frq[nums[i]]>1) return ceil((double)(i+1)/3);
            }  
            return 0;
        }
    };