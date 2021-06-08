#include<bits/stdc++.h>
using namespace std;

void magical_park(char a[][100], int m,int n, int k, int s) {

	//piyush can get out of the park
	bool success = true;

	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			char ch = a[i][j];

			//check
			if(s<k) {
				success = false;
				break;
			}
			if(ch == '*') {
				s += 5;
			}

			else if(ch == '.') {
				s -= 2;
			}
			else {
				break;
			}
			// we also lose 1 unit strength when we move right except for last column
			if(j != n-1) {
				s--;
			}

		}
	}
	if(success) {
		cout<<"Yes"<<endl;
		cout<<s<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
}

int main() {
	

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int m,n,k,s;
	cin>>m>>n>>k>>s;

	char park[100][100];

	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cin>>park[i][j];
		}
	}

	magical_park(park,m,n,k,s);



	return 0;
}