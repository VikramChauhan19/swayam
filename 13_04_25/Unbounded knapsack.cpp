#include<vector>
using namespace std;
class Solution {
    public:
     int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
         vector<int> dp(W + 1, 0);
         for (int w = 0; w <= W; w++) {
             for (int i = 0; i < n; i++) {
                 if (wt[i] <= w) {
                     dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
                 }
             }
         }
         return dp[W];
     }
 };
 