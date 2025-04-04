#include<algorithm>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    public:
        int maxPath;
        int solve(TreeNode* root){ //tc = O(N)
            if(!root) return 0;
            int l = solve(root->left);
            int r = solve(root->right);
            int one = l+r+root->val;
            int two = max(l,r) + root->val;
            int three = root->val;
            maxPath = max({one,two,three,maxPath});
            return max(two,three);
    
        }
        int maxPathSum(TreeNode* root) {
            maxPath = INT_MIN;
            solve(root);
            return maxPath;
            
        }
    };