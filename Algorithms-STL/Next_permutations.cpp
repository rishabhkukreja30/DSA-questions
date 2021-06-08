#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



int main() {


	// #ifndef ONLINE_JUDGEs
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int a[] = {10,34,56,78,90};
	int n =  sizeof(a)/sizeof(int);

	rotate(a,a+2,a+n);

	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;

	vector <int> v{10,20,30,40,50};

	rotate(v.begin(), v.begin() +2, v.end());


	for(int i=0;i<v.size();i++) {
		cout<<v[i]<<" ";
	}	
	cout<<endl;

	vector <int > v1{1,2,3};


	next_permutation(v1.begin(),v1.end());

	
	for(int i=0;i<v1.size();i++) {
		cout<<v1[i]<<" ";
	}	
	cout<<endl;	


	return 0;


}