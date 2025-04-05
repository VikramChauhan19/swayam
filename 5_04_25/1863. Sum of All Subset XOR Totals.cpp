#include<vector>
using namespace std;
class Solution {
    public:
        int sum = 0;
        int n;
        void solve(vector<int>&nums,int i,vector<int>& temp){ //time = l*O(2^N) //space = O(N)
            if(i>=n){
                int Xor = 0;
                for(auto i:temp){
                    Xor ^= i;
                }
                sum += Xor;
                return ;
            }
            temp.push_back(nums[i]);
            solve(nums,i+1,temp);
            temp.pop_back();
            solve(nums,i+1,temp);
        }
    
        int subsetXORSum(vector<int>& nums) {
            n = nums.size();
            vector<int>temp;
            solve(nums,0,temp);   
            return sum;    
        }
    };