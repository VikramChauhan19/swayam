#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int n ;
        vector<int> largestDivisibleSubset(vector<int>& nums) { //sapce = O(N) time = O(N*N)
            n = nums.size();
            sort(nums.begin(),nums.end());
            vector<int>dp(n,1);
            vector<int>preI(n,-1);
            vector<int>res;
    
            int maxl = 0;
            int last_ind = 0;
    
            for(int i = 1;i<n;i++){
                for(int j = 0;j<i;j++){
                    if(nums[i]%nums[j] == 0){
                        if(dp[i]<dp[j]+1){
                            dp[i] = dp[j]+1;
                            preI[i] = j;
                        }
                        if(dp[i]>maxl){
                            maxl = dp[i];
                            last_ind = i; 
                        }
                    }
                }
            }
            while(last_ind != -1){
                res.push_back(nums[last_ind]);
                last_ind = preI[last_ind];
            }
            return res;
    
            
        }
    };