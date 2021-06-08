#include<bits/stdc++.h>
using namespace std;


int main()   {


	int arr[] = {20,30,40,50,100,1100};
	int n = sizeof(arr)/sizeof(int);

	// search in asorted array
	int key = 50;

	bool present = binary_search(arr,arr+n,key);
	cout<<present;


	return 0;
}