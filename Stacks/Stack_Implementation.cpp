#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Stack {
private:
	vector <T> v;
public:
	void push(T data) {
		v.push_back(data);
	}
	bool empty() {
		return v.size() == 0;
	}
	void pop() {
		if(!empty()) {
			v.pop_back();
		}
	}
	T top() {
		return v[v.size() - 1];
	}

};


int main() {

	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	Stack <int> s;

	for(int i= 1;i<=5;i++) {
		s.push(i*i);
	}

	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	}

	Stack <char> s1;

	for(int i= 65;i<=70;i++) {
		s1.push(i);
	}

	while(!s1.empty()) {
		cout<<s1.top()<<endl;
		s1.pop();
	}

	return 0;
}