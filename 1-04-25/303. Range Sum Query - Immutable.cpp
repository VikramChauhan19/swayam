#include<vector>
#include<string>
using namespace std;
class NumArray {
    public:
        vector<int>prefixSum;
        NumArray(vector<int>& nums) {
            int sum = 0;
            for(auto i:nums){
                sum += i;
                prefixSum.push_back(sum);                 }
            
        }
        
        int sumRange(int left, int right) {
            if(left == 0) return prefixSum[right];
            return prefixSum[right]-prefixSum[left-1];
            
        }
    };