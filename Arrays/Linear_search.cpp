#include<bits/stdc++.h>
using namespace std;

int main()  {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, key;
	cin>>n;

	int a[1000];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	cin>>key;

	int i;
	for(i=0;i<n;i++) {
		if(a[i] == key) {
			cout<<a[i] <<" is present at index "<<i<<endl;
			break;
		}
	}
	if(i==n) {
		cout<<"Not present"<<endl;
	}


	return 0;
}