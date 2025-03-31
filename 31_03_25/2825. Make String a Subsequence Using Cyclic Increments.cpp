#include<string>
using namespace std;
class Solution {
    public:
        bool canMakeSubsequence(string str1, string str2) { //TC = O(min(n1,n2)) SC = O(1)
            int n1 = str1.size();
            int n2 = str2.size();
            int i = 0;
            int j = 0;
            while(i<n1 && j<n2){  //O(min(n1,n2))
                if(str2[j]>=str1[i] && str2[j]-str1[i] <= 1){
                    i++;
                    j++;
                }
                else if(str1[i] == 'z' && str2[j] == 'a'){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
            if(j == n2) return true;
            else return false;
    
          
        }
    };