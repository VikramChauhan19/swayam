#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
    public:
        vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> s(nums2.begin(), nums2.end()); //O(n) ->space
                                                                //TC->O(N)
            vector<int> ans(2, 0);
    
            for (auto i : nums1) { // -> N
                if (s.count(i)) ans[0]++;
            }
    
            s = unordered_set<int>(nums1.begin(), nums1.end());
    
            for (auto j : nums2) { //-> N
                if (s.count(j)) ans[1]++;
            }
    
            return ans;
        }
    };
    