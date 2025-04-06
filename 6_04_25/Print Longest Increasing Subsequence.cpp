#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
            vector<int> dp(n, 1);
            vector<int> prevI(n, -1); // space = O(N)
    
            int maxL = 1;
            int maxI = 0;
    
            for (int i = 1; i < n; i++) { //time = O(N*N)
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j]) {
                        if (dp[i] < dp[j] + 1) {
                            dp[i] = dp[j] + 1;
                            prevI[i] = j;
                        }
                    }
                }
                if (dp[i] > maxL) {
                    maxL = dp[i];
                    maxI = i;
                }
            }
    
            vector<int> res(maxL);
            int k = maxL - 1;
            while (maxI != -1) { //time = O(N)
                res[k--] = arr[maxI];
                maxI = prevI[maxI];
            }
    
            return res;
        }
    };
    