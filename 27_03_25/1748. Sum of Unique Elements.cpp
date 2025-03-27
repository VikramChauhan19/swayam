#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    public:
        int sumOfUnique(vector<int>& nums) { //TC - > O(N)
            unordered_map<int,int>m;  //O(N)
            for(auto i:nums){
                m[i]++;
            }
            int sum = 0;
            for(auto i:m){
                if(i.second == 1){
                    sum += i.first;
                }
            }
            return sum;
        }
    };