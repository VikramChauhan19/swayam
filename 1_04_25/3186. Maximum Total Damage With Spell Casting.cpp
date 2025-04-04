#include<vector>
#include<map>
using namespace std;
class Solution {
    public:
        long long memo(vector<long long>&dp,map<int,int>&fm,vector<int>&uniquePower,int i){//space = O(distict power) TC = O(n);
            if(i>=uniquePower.size()) return 0;
            if(dp[i]!= -1) return dp[i];
    
            long long skip = memo(dp,fm,uniquePower,i+1);
            long long take = 0;
            int next = i+1;
            while(next<uniquePower.size() && uniquePower[next]-uniquePower[i]<=2){
                next++;
            }
            long long powerContribution = 1LL * fm[uniquePower[i]] * uniquePower[i];  // Ensure no overflow
            take = powerContribution + memo(dp, fm, uniquePower, next);
            return dp[i] = max(take,skip);
            
        }
        long long maximumTotalDamage(vector<int>& power) {
            map<int ,int>fm;
            vector<int>uniquePower;
            for(auto p:power){
                fm[p]++;
            }
            for(auto f:fm){
                uniquePower.push_back(f.first);
            }
            vector<long long>dp(uniquePower.size(),-1);
            return memo(dp,fm,uniquePower,0);
            
        }
    };