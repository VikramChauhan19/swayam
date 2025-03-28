#include<vector>
using namespace std;
class Solution {
    public:
        int minimumRefill(vector<int>& plants, int capacityA, int capacityB) { //TC = O(n)
            int n  = plants.size();                                             //SC->O(1)
            int i = 0 ;
            int ca = capacityA;
            int j = n-1;
            int cb = capacityB;
            int ans = 0;
            while(i<=j){ // O(n/2)
                if(i == j){
                    if(ca>=cb){
                        if(ca<plants[i]){
                            ca = capacityA;
                            ans++;
                        }
                        ca -= plants[i];
                        i++;
                    }
                    else{
                        if(cb<plants[j]){
                            cb = capacityB;
                            ans++;
                        }
                        cb -= plants[j];
                        j--;
                    }
                    break;
                }
               
               
                
                if(ca < plants[i]){
                    ca = capacityA;
                    ans++;
                }          
                ca -= plants[i];
                i++;
               
               
                if(cb < plants[j]) {
                    cb = capacityB;
                    ans++;
                }            
                cb -= plants[j];
                j--;
                
            }
            return ans;
            
        }
    };