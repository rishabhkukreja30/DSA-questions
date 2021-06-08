#include<bits/stdc++.h>
using namespace std;


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	char a[1000];
	char largest[1000];

	int len = 0;
	int largest_len = 0;

	cin.get();
	for(int i=0;i<n;i++) {
		cin.getline(a,1000);
		// cout<<a<<endl;
		len = strlen(a);
		if(len > largest_len) {
			largest_len = len;
			strcpy(largest, a);
		}
	}

	cout<<largest<<" "<<largest_len<<endl;

	return 0;

}
