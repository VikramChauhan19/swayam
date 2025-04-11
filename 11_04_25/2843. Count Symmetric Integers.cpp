#include<string>
using namespace std;
class Solution {
    public:
        bool symmetric(string &s){//time = O(N*n) N = diff b/w high and low &  n = digit of high
            int n = s.size();
            if(n%2 != 0) return false;
            int front = 0;
            int back = 0;
            for(int i = 0;i<n/2;i++){
                front += s[i]-'0';
                back += s[n-1-i]-'0';
            }
            return front == back;      
        }
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
            for(int i = low;i<=high;i++){
                string s = to_string(i); //space = n
                if(symmetric(s)) count++;
            }
            return count;     
        }
    };