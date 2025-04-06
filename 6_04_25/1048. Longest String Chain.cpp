#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
    public:
        bool checkPred(string s1,string s2){ // to check predecessor
                                            //time = O(L) l = length of biggest string = 16
            int n1 = s1.size();
            int n2 = s2.size();
            if(n2-n1>1 || n1 == n2) return false;
            int i = 0;
            int j = 0;
            while(i<n1 && j<n2){
                if(s1[i] == s2[j]){
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
            return i == n1;
        }
        int longestStrChain(vector<string>& words) {
            int n = words.size();
            sort(words.begin(),words.end(),[](string &a,string &b){ // time = O(n*logn)
                return a.size()<b.size();
            });
            vector<int>dp(n,1); //space = O(N)
            int res = 1;
    
            for(int i = 1;i<n;i++){ //time = O(N*N*L)
                for(int j = 0;j<i;j++){
                    if(checkPred(words[j],words[i])){
                        if(dp[i]<dp[j] +1){
                            dp[i] = dp[j] +1;
                            res = max(dp[i],res);
                        }
                    }
                }
            }
            return res;
            
        }
    };