#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
    public:
        int n;
        unordered_map<string, int> memo;
    
        int solveR(vector<int>& nums, int i, int target, int sum) {
            if (i == n) return target == sum ? 1 : 0;
    
            // Create a unique key for the current state
            string key = to_string(i) + "," + to_string(sum);
    
            // If the result for this state is already computed, return it
            if (memo.find(key) != memo.end()) return memo[key];
    
            // Recurse by adding and subtracting the current number
            int add = solveR(nums, i + 1, target, sum + nums[i]);
            int subtract = solveR(nums, i + 1, target, sum - nums[i]);
    
            // Store the result in the memo table
            return memo[key] = add + subtract;
        }
    
        int findTargetSumWays(vector<int>& nums, int target) {
            n = nums.size();
            memo.clear();
            return solveR(nums, 0, target, 0);
        }
    };