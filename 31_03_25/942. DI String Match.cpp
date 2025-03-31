#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> diStringMatch(string s) { //TC = O(N) SC = O(1)
            int n = s.size();
            int i = 0;
            int j = n;
            vector<int>ans;
            for(auto c:s){ //time = O(n);
                if(c == 'I'){
                    ans.push_back(i);
                    i++;
                }
                else{
                    ans.push_back(j);
                    j--;
                }
            }
            ans.push_back(j);       
            return ans; 
        }
    };