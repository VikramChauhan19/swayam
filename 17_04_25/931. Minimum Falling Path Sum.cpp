#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {//tiem = n*n space = 1
            int n = matrix.size();
            for(int i = n-2;i>=0;i--){
                for(int j = 0;j<n;j++){
                    if(j == 0){
                        matrix[i][j] = matrix[i][j] + min(matrix[i+1][j],matrix[i+1][j+1]);
                    }
                    else if(j == n-1){
                        matrix[i][j] = matrix[i][j] + min(matrix[i+1][j],matrix[i+1][j-1]);
                    }
                    else{
                        matrix[i][j] = matrix[i][j] + min(matrix[i+1][j],min(matrix[i+1][j-1],matrix[i+1][j+1]));
                    }
                }
            }
            return *min_element(matrix[0].begin(), matrix[0].end());
            
        }
    };