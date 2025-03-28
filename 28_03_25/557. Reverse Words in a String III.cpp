#include<string>
#include<sstream>
using namespace std;
class Solution {
    public:
       
        string reverseWords(string s) {
           
            istringstream ss(s);
            string word;
            string ans;
            while(ss>>word){
                reverse(word.begin(),word.end());
                ans+= (word +" ");
            }
            return ans.substr(0,ans.size()-1);
    
            
        }
            
        
    };