#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    public:
        int minimumIndex(vector<int>& nums) {    //TC -> n+n -> O(N)
            int n = nums.size();                 //SC -> n+n ->O(N)
            unordered_map<int,int>left;   // n space
            unordered_map<int,int>right;  //n space
            for(auto i:nums){   // n 
                right[i]++;
            }
    
            for(int i = 0; i<n;i++){    // n
                int num = nums[i];
                left[num]++;
                right[num]--;
                int n1 = i+1;
                int n2 = n -i -1;
                if(left[num]>n1/2 && right[num]>n2/2){
                    return i;
                }
            }
            return -1;        
        }
    };