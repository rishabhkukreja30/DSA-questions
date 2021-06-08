#include<bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	queue <char> q;
	int freq[27] = {0};

	//running a stream until a '.'
	char ch;

	cin>>ch;

	while(ch != '.') {
		//logic will go here
		//insert in q and f table
		q.push(ch);
		freq[ch - 'a']++;


		//query
			while(!q.empty()) {
			int idx = q.front() - 'a';
			if(freq[idx] > 1) {
				q.pop();
			}
			else {
				cout<<q.front()<<endl;
				break;
			}
		}
		//q is empty
		if(q.empty()) {
			cout<<"-1"<<endl;
		}

		cin>>ch;
	}

	return 0;
}