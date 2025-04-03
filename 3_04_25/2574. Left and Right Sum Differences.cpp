#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> leftRightDifference(vector<int>& nums) {
            int n = nums.size();
            vector<int>leftArr(n,0); //space = O(n)
            vector<int>rightArr(n,0);
             for(int i = 1;i<n;i++){ // time = O(n)
                leftArr[i] = leftArr[i-1]+nums[i-1];
                rightArr[n-1-i] = rightArr[n-i]+nums[n-i];
             }
             for(int i = 0;i<n;i++){ //time = O(n)
                nums[i] = abs(leftArr[i]-rightArr[i]);
             }
             return nums;
    
            
        }
    };
