#include<vector>
using namespace std;
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int cur = 0;
            int mx = 0;
            int mn = 0;
            for (auto d : differences) {
                cur = cur + d;
                mx = max(mx, cur);
                mn = min(mn, cur);
                if ((upper - mx) - (lower - mn) + 1 <= 0)
                    return 0;
            }
            return (upper - mx) - (lower - mn) + 1;
        }
    };