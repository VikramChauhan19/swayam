#include<vector>
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
        vector<TreeNode*> solve(int st,int end){
            if(st>end){
                return {NULL};
            }
            if(st == end){
                TreeNode* n = new TreeNode(st);
                return {n};
            }
            vector<TreeNode*>res;
            for(int i = st;i<=end;i++){
                vector<TreeNode*> l_bst = solve(st,i-1); 
                vector<TreeNode*> r_bst = solve(i+1,end);
                for(auto k:l_bst){
                    for(auto j:r_bst){
                        TreeNode* root = new TreeNode(i);
                        root->left = k;
                        root->right = j;
                        res.push_back(root);
                    }
                } 
            }
            return res;
        }
        vector<TreeNode*> generateTrees(int n) {
            return solve(1,n);
            
        }
    };