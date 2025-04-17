#include<vector>
using namespace std;
class Solution {
    public:
        int m,n;
        int dp[71][71][71];
        int solveR(vector<vector<int>>& grid,int r,int c1,int c2){
            if(r >= m) return 0;
            int chery = grid[r][c1];
            if(c1 != c2){
                chery += grid[r][c2];
            }
            if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
            int ans = 0;
            for(int i = -1;i<=1;i++){
                for(int j = -1;j<=1;j++){
                    int new_r = r+1;
                    int new_c1 = c1+i;
                    int new_c2 = c2+j;
    
                    if(new_c1>=0 && new_c1<n && new_c2>=0 && new_c2<n){
                        ans = max(ans,solveR(grid,new_r,new_c1,new_c2));
    
                    }
                }
            }
            return dp[r][c1][c2] =   ans+chery;
        }
        int cherryPickup(vector<vector<int>>& grid) {
    
            m = grid.size();
            n = grid[0].size();
            memset(dp,-1,sizeof(dp));
            return solveR(grid,0,0,n-1);
    
            
        }
    };