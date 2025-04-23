#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int n,vector<int>arr){
    int maX = *max_element(arr.begin(),arr.end());
    int miN = *min_element(arr.begin(),arr.end());
    return maX==miN?0:maX-miN-1;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    cout<<solve(n,arr)<<endl;
	}

}
