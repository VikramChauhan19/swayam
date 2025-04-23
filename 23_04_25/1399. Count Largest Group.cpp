#include<unordered_map>
using namespace std;
class Solution {
    public:
        int digitSum(int n){ //space = O(3^c) c= count of digit of n
        //time = n*c
            int sum = 0;
            while(n){
                int r = n%10;
                sum += r;
                n /= 10;
            }
            return sum;
        }
        int countLargestGroup(int n) {
            unordered_map<int,int>m;
    
            for(int i = 1;i<=n;i++){
                m[digitSum(i)]++;
            }
            int maxi = 0;
            for(auto& v:m){
                maxi = max(maxi,v.second);
            }
            int ans = 0;
            for(auto& v:m){
                if(v.second == maxi){
                    ans++;
                }
            }
    
            return ans;
            
        }
    };