#include<iostream>
#include<algorithm>
using namespace std;


// comparator function
bool compare(int a, int b) {
	cout<<"Comparing "<<a<<" and "<<b<<endl;
	return a >b;

}

int main() {


	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int a[1000];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	sort(a,a+n);

	for(int i=0;i<n;i++) {
		cout<<a[i]<<" " ;
	}
	cout<<endl;

	sort(a,a+n,compare);

	for(int i=0;i<n;i++) {
		cout<<a[i]<<" " ;
	}


	return 0;
}

