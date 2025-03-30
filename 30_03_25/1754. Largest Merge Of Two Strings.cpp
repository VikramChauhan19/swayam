#include<string>
using namespace std;
class Solution {
    public:
        string largestMerge(string word1, string word2) { //TC -> o(n1+n2)^2
                                                        //sc->O(n1+n2)
            int n1 = word1.size();
            int n2 = word2.size();
            string ans = "";
            int i = 0;
            int j = 0;
            while(i<n1 && j<n2){ //O(n1 + n2)
                if(word1[i]>word2[j]){
                    ans+= word1[i];
                    i++;
                }
                else if(word2[j]>word1[i]){
                    ans+= word2[j];
                    j++;
                }
                else{
                    if(word1.substr(i)>word2.substr(j)){ //O(n1 + n2) tc,sc
                        ans+= word1[i];
                        i++;
                    }
                    else{
                        ans+= word2[j];
                        j++;
                    }
                }
            }
            while(i<n1){
                ans+= word1[i];
                i++;
            }
            while(j<n2){
                ans+= word2[j];
                j++;
            }
            return ans;
            
        }
    };
    /*Optimized Code    Final Complexity: O(n1 + n2)
    class Solution {
    public:
        string largestMerge(string word1, string word2) {
            string ans = "";
            int i = 0, j = 0;
            
            while (i < word1.size() && j < word2.size()) {
                // Instead of substr(), compare directly
                if (word1.compare(i, word1.size() - i, word2, j, word2.size() - j) > 0) {
                    ans += word1[i++];
                } else {
                    ans += word2[j++];
                }
            }
            
            ans += word1.substr(i);
            ans += word2.substr(j);
    
            return ans;
        }
    };*/