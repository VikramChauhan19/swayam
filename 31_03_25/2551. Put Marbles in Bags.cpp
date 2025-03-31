#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) { //TC->O(nlogn) SC->O(n-1)
            int n = weights.size();
            int m = n-1;
    
            vector<int>pairS(m); //space->O(n-1)
            for(int i = 0;i<m;i++){//time->O(n-1)
                pairS[i] = weights[i]+ weights[i+1];
            }
            sort(pairS.begin(),pairS.end()); //time->O(n-1*logn-1)
            long maxS = 0;
            long minS = 0;
    
            for(int i = 0;i<k-1;i++){ //time->O(k)
                minS += pairS[i]; 
                maxS += pairS[m-1-i]; 
            }
            return maxS-minS;
            
        }
    };