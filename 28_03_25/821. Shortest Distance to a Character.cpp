#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        vector<int> shortestToChar(string s, char c) { //TC->O(n*m)
            vector<int>ind;                            //sc->O(n)
            vector<int>ans(s.size(),INT_MAX);
            for(int i = 0;i<s.size();i++){
                if(s[i] == c){
                    ind.push_back(i);
                }
            }
            for(int i = 0;i<s.size();i++){
                for(int j = 0;j<ind.size();j++){
                    ans[i] = min(ans[i],abs(i-ind[j]));
                }
            }
            return ans;
            
        }
    };