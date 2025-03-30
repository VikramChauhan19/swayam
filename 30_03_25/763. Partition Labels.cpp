#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        vector<int> partitionLabels(string s) { // tc->O(N) sc -> O(N)
            vector<int> lastIndex(26, 0); 
            vector<int> ans;
            
            
            for (int i = 0; i < s.size(); i++) {
                lastIndex[s[i] - 'a'] = i;
            }
            
            int start = 0, end = 0;
            for (int i = 0; i < s.size(); i++) {
                end = max(end, lastIndex[s[i] - 'a']); 
                
                if (i == end) {
                    ans.push_back(end - start + 1);
                    start = i + 1;
                }
            }
            return ans;
        }
    };
    