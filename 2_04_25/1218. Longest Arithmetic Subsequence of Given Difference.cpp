#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {//TC = O(N) SC = O(N)
            int n = arr.size();
            unordered_map<int,int>m; //first-> last element, second = length of subsequence till last element
            int result = 0;
            for(auto i:arr){
                int prev = i-difference;
                m[i] = m[prev]+1;
                result = max(result,m[i]);
    
            }
            return result;
            
        }
    };