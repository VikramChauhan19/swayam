#include<vector>
using namespace std;
class Solution {
    public:
        int n;
        int memo(vector<int>&days,vector<int>&costs,int i,vector<int>&dp){ //SC -> O(N)
            if(i>=n) return 0;                                          //TC ->)(n*n)
            if(dp[i] != -1) return dp[i];
            int cost1 = costs[0] + memo(days,costs,i+1,dp);
    
            int j = i;
            int maxD = days[i] + 7;
            while(j<n && days[j]<maxD){
                j++;
            }
            int cost7 = costs[1] + memo(days,costs,j,dp);
    
            j = i;
            maxD = days[i] + 30;
            while(j<n && days[j]<maxD){
                j++;
            }
            int cost30 = costs[2] + memo(days,costs,j,dp);
    
            dp[i] = min(cost1,min(cost7,cost30)); 
            return dp[i];     
        }
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            n = days.size();
            vector<int>dp(n+1,-1);
            return memo(days,costs,0,dp);
                   
        }
    };