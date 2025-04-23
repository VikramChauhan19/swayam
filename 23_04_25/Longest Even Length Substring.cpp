/*
Your team is participating in ICPC preliminaries. To qualify for the regional contest, you have to solve at least one problem of the competition. The easiest problem among them is that you have given a string ‘STR’ containing digits, and you have to find the longest substring of length 2P such that the sum of right ‘P’ elements and left ‘P’ elements are equal.
*/
#include<string>
using namespace std;
bool isEven(string &str,int i ,int j){ //space = O(1) //time = n^3
    int half = (j-i+1)/2+i;
    int left = 0;
    while(i<half){
        left += (str[i]-'0');
        i++;
    }
    int right = 0;
    while(j>=half){
        right += (str[j]-'0');
        j--;
    }
    return left == right;
}
int longestLength(string &str) {
    // Write your code here.
    int n = str.size();
    int ans = 0;

    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            if((j-i+1)%2 != 0)continue;
            else{
                if(isEven(str,i,j)){
                    ans = max(ans,j-i+1);
                }
            }
        }
    }
    return ans;
}