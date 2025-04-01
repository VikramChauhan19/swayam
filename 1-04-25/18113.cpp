#include<string>
#include<iostream>
#include<sstream>
#include<deque>
using namespace std;
class Solution {
    public:
        bool areSentencesSimilar(string sentence1, string sentence2) {// TC = O(n) sp = O(n)
            if(sentence2.size()> sentence1.size()){
                swap(sentence1,sentence2); //o(1)
            }
            deque<string> deq1,deq2;
    
            stringstream ss1(sentence1);
            string token;
            while(ss1>>token){  //O(n1)
                deq1.push_back(token);
            }
            
            stringstream ss2(sentence2);
            
            while(ss2>>token){   //O(n2)
                deq2.push_back(token);
            }
    
            while(!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front()){ //O(n)
                deq1.pop_front();
                deq2.pop_front();
            }
            while(!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back()){
                deq1.pop_back();
                deq2.pop_back();
            }
            return deq2.empty();
            
        }
    };
    int main(){
        Solution s1;
        string t1  =  "djfsjdfjs";
        string t2 = "jsjfjsfksjdf";
        bool b = s1.areSentencesSimilar(t1,t2);
        cout<<b;

    }