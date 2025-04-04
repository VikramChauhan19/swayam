#include<vector> 
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> result;
            if(!root) return result;
            queue<TreeNode*>q;
            q.push(root); //space = O(2^H)
            bool ltr = true; // flag to decide direction
    
            while(!q.empty()){ //time = O(N)
                int size = q.size();
                vector<int>temp(size);
                for(int i = 0;i<size;i++){
                    TreeNode* fr = q.front();
                    q.pop();
                    int index = ltr == true? i : size-1-i; // index depending on direction
                    temp[index]= fr->val; 
                    if(fr->left) q.push(fr->left);
                    if(fr->right) q.push(fr->right);
                }
                result.push_back(temp);
                ltr = !ltr; // reversing the direction
            }
            return result;
            
        }
    };