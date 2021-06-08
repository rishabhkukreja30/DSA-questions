#include<bits/stdc++.h>
using namespace std;

int main()  {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int a[1000];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	int largest = INT_MIN;
	int smallest = INT_MAX;

	for(int i=0;i<n;i++) {
		if(a[i] > largest) {
			largest = a[i];
		}
		if(a[i] < smallest) {
			smallest = a[i];
		}
	}

	
	cout<<"Largest: "<<largest<<endl;
	cout<<"Smallest: "<<smallest<<endl;

	//or
	for(int i=0;i<n;i++) {
		largest  = max(largest, a[i]);
		smallest = min(smallest, a[i]);
	}

	cout<<"Largest: "<<largest<<endl;
	cout<<"Smallest: "<<smallest<<endl;

}