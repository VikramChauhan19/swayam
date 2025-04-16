#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int x, int y ,int z){ //longest palindromic subsequence
    vector<int>v = {x,y,z};
    sort(v.begin(),v.end());
    if(v[0]%2 == 1 && v[1]%2 == 1){
        return v[0]+v[1]-1;
    }
    else return v[0]+v[1];
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,y,z;
	    cin>>x>>y>>z;
	    cout<<solve(x,y,z)<<endl;
	}

}