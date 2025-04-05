#include<algorithm>
#include<vector>
#include<map>
#include<queue>
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
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            
            map<int,map<int,vector<int>>> nodes;
            queue<pair<TreeNode*, pair<int,int>>> q;
            vector<vector<int>> ans;
            if(!root ) return ans;
            q.push({root,{0,0}});
            while(!q.empty()){
                pair<TreeNode*,pair<int,int>> cur = q.front();
                q.pop();
                TreeNode* fn = cur.first;
                int h = cur.second.first;
                int level = cur.second.second;
    
                nodes[h][level].push_back(fn->val);
                if(fn->left){
                    q.push({fn->left,{h-1,level+1}});
                }
                if(fn->right){
                    q.push({fn->right, {h+1,level+1}});
                }
            }
            for(auto i:nodes){
                vector<int> temp;
                for(auto j:i.second){ 
                    sort(j.second.begin(),j.second.end());              
                    for(auto k:j.second){
    
                        temp.push_back(k);
                    }
                }
                ans.push_back(temp);
            }
            return ans;
    
        }
    };