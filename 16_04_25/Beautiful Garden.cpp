#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int n,int k,int d,vector<int>&time){
    int np = n-k;
    sort(time.begin(),time.end());
    int ans = 0;
    for(int i = 0;i<np;i++){
        ans += 1+((d-1)/time[i]);
    }
    return ans;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k,d;
	    cin>>n>>k>>d;
	    vector<int>time(n);
	    for(int i = 0;i<n;i++){
	        cin>>time[i];
	    }
	    cout<<solve(n,k,d,time)<<endl;
	}

}