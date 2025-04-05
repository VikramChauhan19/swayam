#include<vector>
#include<map>
#include<queue>
using namespace std;
class Node{
   public: 
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
    public:
      vector <int> bottomView(Node *root) {//tc = O(NlogN) sc = O(N)
          // Your Code Here
          vector<int>result;
          if(!root) return result;
          map<int,pair<int,int>>m; //space = O(N) // horizontal distance,height,val
          queue<pair<Node*,pair<int,int>>>q;//space - = O(N)
          q.push({root,{0,0}});
          while(!q.empty()){ //time = O(N)
              auto fr = q.front();
              q.pop();
              int hor = fr.second.first;
              int ver = fr.second.second;
              Node* n = fr.first;
              m[hor] = {ver,n->data}; //time=O(logN)
              if(n->left){
                  q.push({n->left,{hor-1,ver+1}});
              }
              if(n->right){
                  q.push({n->right,{hor+1,ver+1}});
              }
          }
          for(auto i:m){
              result.push_back(i.second.second);
          }
          return result;
      }
  };