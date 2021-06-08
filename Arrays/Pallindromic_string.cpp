#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(char a[]) {
	int i=0;
	int j= strlen(a)  - 1;

	while(i<j) {
		if(a[i] == a[j]) {
			i++;
			j--;
		}
		else {
			return false;
		}
	}
	return true;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char a[1000];
	cin.getline(a, 1000);


	if(isPalindrome) {
		cout<<"Palindromic string"<<endl;
	}
	else {
		cout<<"Not a palindrome";
	}

	return 0;
}