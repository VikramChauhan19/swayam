#include<vector>
#include<algorithm>
using namespace std;
class Solution { //space = s*s time = s*s*s
    public:
        int solve(vector<int>&cuts,int i,int j,vector<vector<int>>&dp){
            if(i+1 == j) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            int ans = INT_MAX;
    
            for(int k =i+1;k<j;k++){ //s
                int temp = solve(cuts,i,k,dp) + solve(cuts,k,j,dp)+ (cuts[j]-cuts[i]);
                ans = min(ans,temp);
            }
            return dp[i][j] =  ans;
        }
        int minCost(int n, vector<int>& cuts) {
            cuts.push_back(0);
            cuts.push_back(n);
            sort(cuts.begin(),cuts.end()); //s*logn
            vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1)); //s*s
            return solve(cuts,0,cuts.size()-1,dp);
            
        }
    };