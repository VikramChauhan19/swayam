#include<vector>
#include<queue>
using namespace std;
class Solution {
    public:
        int m;
        int n;
        int k;
        vector<vector<int>>directions = {{0,1}, {0,-1},{1,0},{-1,0}};
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            m = grid.size();
            n = grid[0].size();
            k = queries.size();
    
            vector<pair<int,int>>sortedQueries; //space-> 0(k)
            for(int i = 0;i<k;i++){
                sortedQueries.push_back({queries[i],i});
            }
            sort(sortedQueries.begin(),sortedQueries.end()); // klogk
    
            vector<int>result(k,0);
    
            priority_queue<vector<int>,vector<vector<int>>,greater<>> mh; //space = m*n
            vector<vector<bool>>visited(m,vector<bool>(n,false)); //space = m*n
            int points = 0;
            mh.push({grid[0][0],0,0});
            visited[0][0] = true;
            /*T.C : O(KlogK) + m*nlog(m*n)) 
            - Notice that we won't visit any cell more than once (we mark them visited). 
             Total cells = m*n and heap can have m*n cells in worst case
            //S.C : O(m*n)
            */
    
            for(int i = 0;i<k;i++){ //O(k)
                int queryVal = sortedQueries[i].first;
                int idx = sortedQueries[i].second;
                while(!mh.empty() && mh.top()[0]<queryVal ){ //WORST CASE-> m*n
                    points++;
                    int i = mh.top()[1];
                    int j = mh.top()[2];
                    mh.pop();//log(m*n)
                    for(auto dir:directions){
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]){
                            mh.push({grid[i_][j_],i_,j_});//log(m*n)
                            visited[i_][j_] = true;
                        }
                    }
    
                }
                result[idx] = points;
    
            }
            return result;
            
        }
    };