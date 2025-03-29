#include<string>
using namespace std;
class Solution {
    public:
        int reverseDegree(string s) { //TC->O(N) SP->O(1)
            int ans = 0;
            for(int i = 0;i<s.size();i++){
                ans += ('z'-s[i]+1)*(i+1);
            }
            return ans;
            
        }
    };