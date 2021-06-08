#include<bits/stdc++.h>
using namespace std;

int multiply(int a ,int b) {
	//base case
	if(a==0 or b==0){
		return 0;
	}
	//rec case
	return a + multiply(a ,b-1);

}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a ,b;
	cin>>a>>b;

	cout<<multiply(a, b)<<endl;


	return 0;
}