#include<bits/stdc++.h>
using namespace std;

bool checkExpression(string str) {
	stack <char> s;

	for(int i= 0;i<str.size(); i++) {
		if(str[i] == '(') {
			s.push(str[i]);
		}
		else if(str[i] == ')') {
			if(s.empty() || s.top() != '(') {
				return false;
			}
			s.pop();
		}
	}
	return s.empty();
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;
	cin>>s;

	bool isValid = checkExpression(s);
	cout<<isValid;

	return 0;
}