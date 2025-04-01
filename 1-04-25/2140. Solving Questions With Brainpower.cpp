#include<vector>
using namespace std;
class Solution {
    public:
        int n;
        /*long long solveR(vector<vector<int>>&questions,int i,vector<long long>&dp){
            if(i >= n){
                return 0;
            }
            if(dp[i] != -1) return dp[i];
            long long pick = questions[i][0] + solveR(questions,i+questions[i][1]+1,dp);
            long long notPick = solveR(questions,i+1,dp);
            dp[i] =  max(pick,notPick);
            return dp[i];
        }
        */
        
        long long mostPoints(vector<vector<int>>& questions) {//TC = O(n) SP = O(N)
            n = questions.size();
            vector<long long>dp(n+1,0); //space = n;
            //return solveR(questions,0,dp);
            for(int i = n-1;i>=0;i--){ //time = n
                int points = questions[i][0];
                int brainpower = questions[i][1];
                long long pick =  points;
                
                if(i+brainpower+1>= n) {
                    pick  = points;                
                }
                else {
                    pick = points + dp[i+brainpower+1];
                }
                long long notPick  = dp[i+1];
                
                dp[i] = max(pick,notPick);
    
            }
            return dp[0];
        }
    };