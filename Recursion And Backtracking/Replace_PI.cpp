#include<bits/stdc++.h>
using namespace std;

void replacePI(char a[], int i) {
	//base case
	if(a[i] == '\0' or a[i+1] == '\0') {
		return;
	}

	//look for pi at current location
	if(a[i] == 'p' and a[i+1] == 'i') {
		//shfting + replacement by 3.14
		int j = i + 2;
		//take j to the end of the array
		while(a[j] != '\0') {
			j++;
		}
		//shifting (right to left) 
		while(j >= i+2) {
			a[j+2] = a[j];
			j--;
		}

		//replacement  + recursive call for rem part
		a[i] = '3';
		a[i+1] = '.';
		a[i+2] = '1';
		a[i+3] = '4';
		replacePI(a, i+4);
	}
	else {
		//go to the next position
		replacePI(a , i +1);
	}
	return;
}


int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char a[1000];
	cin>>a;
	replacePI(a, 0);
	cout<<a;

	return 0;
}