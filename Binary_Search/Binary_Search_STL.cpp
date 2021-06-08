#include<iostream>
#include<algorithm>
using namespace std;


int main() {

	// #ifndef ONLINE_JUDGEs
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif


	int arr[] = {20,30,40,40,40,40,50,100,1100};

	int n = sizeof(arr)/sizeof(int);

	int key;
	cin>>key;

	bool present = binary_search(arr,arr+n, key);
	if(present) {
		cout<<"present"<<endl;
	}
	else {
		cout<<"absent"<<endl;
	}


	// get the index of the element
	// lower_bound(s,e,key) and upper_bound(s,e,key) - they give the address

	auto lb = lower_bound(arr,arr+n, 40);
	cout<<lb-arr<<endl;


	auto up = upper_bound(arr,arr+n, 40);
	cout<<up-arr<<endl;

	cout<<"Freq of 40 is "<<up-lb<<endl;

	return 0;
}
