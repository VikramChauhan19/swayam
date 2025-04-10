#include<string>
using namespace std;
class Solution {
    public:
        long long solve(string s,int limit,string inputString){
            if(s.size()<inputString.size()) return 0;
            long long count= 0;
    
            string trailString = s.substr(s.length()-inputString.length());
            int remainL = s.size()-inputString.size();
    
            for(int i = 0;i<remainL;i++){
                int digit = s[i]-'0';
                if(digit<=limit){
                    count += digit*pow(limit+1,remainL-1-i);
                }
                else{
                    count += pow(limit+1,remainL-i);
                    return count;
                }
            }
            if(trailString>=inputString) count++;
    
            return count;
    
        }
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            string st = to_string(start-1);
            string fn = to_string(finish);
    
            return solve(fn,limit,s)-solve(st,limit,s);       
        }
    };