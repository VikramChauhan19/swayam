#include<string>
using namespace std;
class Solution {
    public:
        bool canChange(string start, string target) { //TC = O(n) sp = O(1)
            int n = start.size();
            int i = 0;
            int j = 0;
            while(i<n || j<n){ //time = n
        
                while(i<n && start[i] == '_') i++;
                while(j < n && target[j] == '_') j++;
                
                
                if(i == n || j == n) return i == j;
                       
                if(start[i] != target[j]) return false;
                
                if (start[i] == 'L' && i < j) return false; // 'L' can only move left
                if (start[i] == 'R' && i > j) return false;
                
                i++;
                j++;
                
            }
            return true;     
        }
    };