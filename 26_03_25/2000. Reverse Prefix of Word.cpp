#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        void reverse(string &s,int l, int r){
            while(l<r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        string reversePrefix(string word, char ch) {
            int x = word.find(ch);
            if(x == string::npos){
                return word;
            }
            reverse(word,0,x);
            return word;
            
        }
    };