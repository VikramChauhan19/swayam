#include<string>
using namespace std;
class Solution {
    public:
        int minimumLength(string s) {
            int n = s.size();
            int i = 0;
            int j = n-1;
            char ch;
            while(i<j && s[i] == s[j]){ //tc = O(n) sc = O(1)
                ch = s[i];
                while(i<n && s[i] == ch) i++;
                while(j>=0 && s[j] == ch) j--;
            }
            return j-i<0?0:j-i+1;
            
        }
    };
