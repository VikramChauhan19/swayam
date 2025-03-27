#include<vector>
#include<unordered_map>
using namespace std;
//Soln -> 1
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

//SOln -> 2 (optimized)
class Solution {
    public:
        int majorityE(vector<int>&nums){ // TC = O(n)
            int count = 0;               // SC = O(1)
            int cand = 0;
            for(auto i:nums){
                if(count == 0) cand = i;
                if(cand == i) count++;
                else count--;
            }
            return cand;
    
        }
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            
            int c = 0;
            int cand = majorityE(nums);
            int remain = count(nums.begin(),nums.end(),cand);
            for(int i = 0;i<n;i++){
                int num = nums[i];
                if(num == cand){
                    c++;
                    remain--;
                }
                int n1 = i+1;
                int n2 = n-i-1;
                if(c>n1/2 && remain > n2/2){
                    return i;
                }
            }
            return -1;
    
            
        }
    };