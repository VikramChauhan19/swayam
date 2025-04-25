
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            vector<int>visited(rooms.size(),0);
            queue<int>q;
            visited[0] =1;
            q.push(0);
            while(!q.empty()){
                int size = q.size();
                int cur = q.front();
                q.pop();
                for(auto i : rooms[cur]){
                    if(!visited[i]){
                        visited[i] =1;
                        q.push(i);
                    }
    
                }
            }
            for(int i = 0;i<visited.size();i++){
                if(visited[i] == 0) return false;
            }
            return true;
            
        }
    };

    int main() {
        Solution sol;
        vector<vector<int>> rooms = {{1}, {2}, {3}, {}};  // Example input
        cout << (sol.canVisitAllRooms(rooms) ? "True" : "False") << endl; // Output: True
        return 0;
    }