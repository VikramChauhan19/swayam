#include<vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>>res;
        int n;
        void solve(vector<int>&nums,int i,vector<int>&temp){ //space = O(N) time = O(N*2^N)
            if(i>=n){
                res.push_back(temp);
                return ;
            }
            temp.push_back(nums[i]);
            solve(nums,i+1,temp);
            temp.pop_back();
            solve(nums,i+1,temp);
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            n = nums.size();
            vector<int>temp;
            solve(nums,0,temp);
            return res;
            
        }
    };