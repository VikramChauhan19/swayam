#include<vector>
using namespace std;
class Solution {
    public:
        int countDigit(int n){
            int count = 0;
            while(n!=0){
                n = n/10;
                count++;
            }
            return count;
        }
        int findNumbers(vector<int>& nums) {
            int res = 0;
            for(auto i:nums){
                if(countDigit(i)%2 == 0){
                    res++;
                }
            }
            return res;
            
        }
    };