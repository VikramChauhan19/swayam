#include<vector>
using namespace std;
class Solution {
    public:
      int LongestBitonicSequence(int n, vector<int> &nums) {
     
          vector<int>dpl(n,1); //O(N)
          vector<int>dpr(n,1);
          
          for(int i = 1;i<n;i++){ // time = O(n*n)
              for(int j = 0;j<i;j++){
                  if(nums[i]>nums[j]){
                      if(dpl[i]<dpl[j]+1){
                          dpl[i] = dpl[j] +1;
                      }
                  }
                  if(nums[n-1-i]>nums[n-1-j]){
                      if(dpr[n-1-i]<dpr[n-1-j]+1){
                          dpr[n-1-i] = dpr[n-1-j]+1;
                      }
                  }
              }
          }
          int result = 0;
          for(int i = 0;i<n;i++){ //time = O(N)
              if(dpl[i] != 1 && dpr[i] != 1){
                  result = max(result, dpl[i] + dpr[i] -1);
              }
          }
          return result;
          // code here
      }
  };