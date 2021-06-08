#include<bits/stdc++.h>
using namespace std;

class fun {
public:
	void operator()(string s) {
		cout<<"Having fun with "<<s;
	}
};


class  person{
public:
	string name;
	int age;

	person(string n, int a) {
		name = n;
		age = a;
	}
};

class  personCompare {
public:
	bool operator()(person a, person b) {
		cout<<"Comparing "<<a.age<<" with "<<b.age<<endl;
		return a.age > b.age;
	}
};


int main() {

	fun f;    // constructor
	f("C++");    // overloaded () operator = function call where f is an object  - functor

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	priority_queue <person	, vector <person> , personCompare > pq;

	for(int i=0;i<n;i++) {
		string name;
		int age;
		cin>>name>>age;
		person p(name, age);
		pq.push(p);
	}


	int k=3;
	for(int i=0;i<k;i++) {
		person p =pq.top();
		cout<<p.name<<" "<<p.age<<endl;
		pq.pop();
	}













	return 0;
}