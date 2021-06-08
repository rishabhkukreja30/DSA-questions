#include<bits/stdc++.h>
using namespace std;

//cin.get() reads a single character
//put a loop to read characters till you get a new line character ('\n')

void readline(char a[], int maxlen, char delim = '\n') {
	int i=0;
	char ch = cin.get();
	while(ch != delim) {
		a[i] = ch;
		i++;
		if(i == maxlen-1) {
			break;
		}
		ch = cin.get();
	}
	a[i] = '\0';
	return;
}



int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char a[1000];
	//readline(a,1000, '$');
	cin.getline(a,1000);

	cout<<a;









	return 0;
}