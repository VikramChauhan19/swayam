#include<unordered_map>
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
        unordered_map<TreeNode*,int>m;
        int maxd = 0;
        void depth(TreeNode* root,int d){
            if(!root) return ;
            maxd = max(maxd,d);
            m[root] = d;
            depth(root->left,d+1);
            depth(root->right,d+1);
        } 
        TreeNode* LCS(TreeNode* root){
            if(!root) return nullptr;
            if(m[root] == maxd) return root;
            TreeNode* l = LCS(root->left);
            TreeNode* r = LCS(root->right);
            if(l && r) return root;
            else if( l && !r) return l;
            else return r;
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            depth(root,0);
            return LCS(root);     
        }
    };