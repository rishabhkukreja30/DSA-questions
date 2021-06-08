#include<bits/stdc++.h>
using namespace std;

int main() {

	int arr[] = {10,20,11,9,8,11,10};
	int n = sizeof(arr) / sizeof(int);

	set <int> s;
	for(int i=0;i<n;i++) {
		s.insert(arr[i]);
	}

	//print all the elements
	for(set <int> :: iterator it = s.begin(); it!=s.end(); it++) {
		cout<< *(it)<<" ";
	}

	s.erase(10);

	auto it = s.find(11);
	s.erase(it);

	cout<<endl;
	for(set <int> :: iterator it = s.begin(); it!=s.end(); it++) {
		cout<< *(it)<<" ";
	}
	cout<<endl;

	set <pair <int,int> > s1;
	s1.insert(make_pair(10,1));
	s1.insert(make_pair(10,5));
	s1.insert(make_pair(20,1));
	s1.insert(make_pair(20,100));
	s1.insert(make_pair(5,1));
	s1.insert(make_pair(5,3));

	s1.erase(s1.find((make_pair(5,3))));
	s1.insert(make_pair(5,4));

	auto it1 = s1.lower_bound(make_pair(20,1));
	cout<<it1->first<<" "<<it1->second<<endl;


	auto it2 = s1.upper_bound(make_pair(20,1));
	cout<<it2->first<<" "<<it2->second<<endl;

	//at least 20
	auto it3 = s1.upper_bound(make_pair(20,INT_MAX));
	cout<<it3->first<<" "<<it3->second<<endl;

	for(auto p : s1) {
		cout<<p.first<<" and "<<p.second<<endl;
	}


	return 0;
}

