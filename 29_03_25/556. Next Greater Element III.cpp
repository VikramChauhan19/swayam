#include<string>
using namespace std;
class Solution {
    public:
        int nextGreaterElement(int n) {  //TC-> O(logn) & ST->O(logN)
            string s = to_string(n); //log(n)
            int i = s.size()-2;
            while(i>=0 && s[i]>=s[i+1]){  //logn
                i--;
            }
    
            if(i == -1) return -1;
            int j = s.size()-1;
            while(s[i]>=s[j]){  //logn
                j--;
            }
            swap(s[i],s[j]); //O(1)
            reverse(s.begin()+i+1,s.end());  //log(n)
            long ans = stol(s);   //log(n)
            if(ans>INT_MAX) return -1;
            return ans;
                
        }
    };