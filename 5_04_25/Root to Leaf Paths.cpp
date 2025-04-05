#include<vector> 
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
  vector<vector<int>> result;
    void solve(Node* root,vector<int>&temp){ //space = O(1) //time = O(N)
        if(!root){
            return;
        }
        temp.push_back(root->data);
        if (!root->left && !root->right) {
            result.push_back(temp);
        } else {
            solve(root->left, temp);
            solve(root->right, temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<int>temp;
        solve(root,temp);
        return result;
        
    }
};