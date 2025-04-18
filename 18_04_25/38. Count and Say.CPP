#include<string>
using namespace std;
class Solution {
    public:
        string runLengthEncoding(string &s){
            int n = s.size();
            string encoding = "";
            for(int i = 0;i<s.size();i++){
                int count = 1;
                while(i+1<n && s[i] == s[i+1]){
                    count++;
                    i++;
                }
                encoding += to_string(count);
                encoding += s[i];
            }
            return encoding;
        }
        string countAndSay(int n) {
            string s = "1";
            for(int i = 2;i<=n;i++){
                s = runLengthEncoding(s);
            }
            return s;       
        }
    };