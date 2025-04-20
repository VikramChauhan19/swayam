#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {// space = O(n) time = O(n)
            unordered_map<int,int>m;
    
            for(auto i:answers){
                m[i]++;
            }
            int total = 0;
    
            for(auto i:m){
                int x = i.first;
                int count = i.second;
                
                int group = ceil((double)count/(x+1));
                total += group*(x+1); 
            }
            return total;
            
        }
    };