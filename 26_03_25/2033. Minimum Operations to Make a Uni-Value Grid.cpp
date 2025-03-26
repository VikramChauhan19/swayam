#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int>vals;
            for(auto i:grid){
                for(auto j:i){
                    vals.push_back(j);
                }
            }
            sort(vals.begin(),vals.end());
            int n = vals.size();
            int mid = n/2;
            int count = 0;
            for(int i = 0;i<n;i++){
                int diff = abs(vals[i]-vals[mid]);
                if(diff%x == 0){
                    count += diff/x;
                }
                else return -1;
            }
            return count;
            
        }
    };