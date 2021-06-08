#include<iostream>
#include<set>
#include<bits/stdc++.h>
#include<string>
using namespace std;

typedef multiset<int> :: iterator It;

class person_compare{
public:
	bool operator()(pair<string, int> p1, pair<string ,int> p2) {
		return p1.second < p2.second;
	}
};

int main() {

	int arr[] = {10,20,30,20,30,30,30,10,30};
	int n = sizeof(arr) / sizeof(int);
	multiset <int> m(arr, arr+n);

	for(auto x: m) {
		cout<<x<<" ";
	}
	cout<<endl;

	m.erase(20);
	m.insert(80);
	for(auto x: m) {
		cout<<x<<" ";
	}
	cout<<endl;

	cout<<m.count(10)<<endl;

	//find
	auto it = m.find(30);
	cout<<(*it)<<endl;

	//get all elements which are equal to 30
	pair <It, It> range = m.equal_range(30);

	for(auto it = range.first; it!=range.second;it++) {
		cout<<*it<<" ";
	}
	cout<<endl;

	//lower >= and upper bound >
	for(auto it = m.lower_bound(10); it != m.upper_bound(77); it++) {
		cout<<*it<<" ";
	}
	cout<<endl;

	//custom data type
	pair <string ,int> p1 = make_pair("B", 100);
	pair <string ,int> p2 = make_pair("A", 40);
	pair <string ,int> p3 = make_pair("C", 120);
	pair <string ,int> p4 = make_pair("D", 10);

	multiset < pair <string , int> > m1;
	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);
	m1.insert(p4);

	for(auto p : m1) {
		cout<<p.first<<" "<<p.second<<endl;
	}
	cout<<endl;

	multiset < pair <string , int>, person_compare > m2;
	m2.insert(p1);
	m2.insert(p2);
	m2.insert(p3);
	m2.insert(p4);

	for(auto p : m2) {
		cout<<p.first<<" "<<p.second<<endl;
	}


	return 0;
}