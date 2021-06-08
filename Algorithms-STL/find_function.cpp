#include<bits/stdc++.h>
using namespace std;

int main() {

	int arr[] =  {1,10,11,9,100};
	int n = sizeof(arr)/sizeof(int);

	int key = 11;
	auto it  = find(arr,arr+n,key);
	cout<<it<<endl;
	cout<<it-arr<<endl;

	return 0;
}