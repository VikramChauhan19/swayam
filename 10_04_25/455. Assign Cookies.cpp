#include<vector>
#include<algorithm>
using namespace std;
class Solution {

    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {//time = O(nlogn) space = O(1);
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
    
            int j = 0;
            int i = 0;
            while(j<s.size() && i<g.size()){
                if(g[i]<=s[j]){
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
            return i;
                 
        }
    };