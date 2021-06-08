#include<bits/stdc++.h>
using namespace std;


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int b[] = {1,2,3};
	cout<<b<<endl;       // returns address

	char a[] = {'a','b', 'c', '\0'};
	cout<<a<<endl;    // returns content of the array


	//input
	char s[10];
	cin>>s; 

	cout<<s<<endl;

	char c[] = "hello";
	cout<<sizeof(c)<<endl;

	char s1[] = {'h', 'e', 'l','l','o'};  // doesn't terminate with a NULL

	cout<<s1<<" "<<sizeof(s1)<<endl;   // returns garbage value as well





	return 0;

}