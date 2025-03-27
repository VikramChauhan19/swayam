#include<vector>
using namespace std;
class Solution {
    public:
        int countPrimes(int n) {        //SC -> O(N);
            if (n <= 1) return 0;       //TC ->O(N* rootN)
    
            vector<bool>isPrime(n,true);
            isPrime[0] = false;
            isPrime[1] = false;
            for(int i = 2;i*i<n;i++){
                if(isPrime[i] == true){
                    for(int j = 2;i*j<n;j++){
                        isPrime[i*j] = false;
                    }
                }
            }
            return count(isPrime.begin(),isPrime.end(),true);
            
        }
    };