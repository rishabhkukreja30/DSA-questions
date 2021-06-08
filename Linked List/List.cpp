#include<iostream>
#include<list>
#include<string>
using namespace std;

int main() {

	list <int> l;

	//initialize
	list <int> l1{1,2,3,10,8,5};

	//different datatype as list is a template class
	list <string> l2{"apple", "guava","mango", "banana"};
	l2.push_back("pineapple");

	for(auto s: l2) {
		cout<<s<<" ";
	}

	l2.sort();
	cout<<endl;
	for(auto s: l2) {
		cout<<s<<" ";
	}
	l2.reverse();

	cout<<endl;
	for(auto s: l2) {
		cout<<s<<" ";
	}
	l2.pop_front();

	cout<<endl;
	for(auto s: l2) {
		cout<<s<<" ";
	}

	l2.push_front("kiwi");


	cout<<endl;
	//iterate over the list and print the data
	for(auto it= l2.begin(); it != l2.end(); it++) {
		cout<<(*it)<<" ";
	}

	l2.remove("guava");


	cout<<endl;
	for(auto s: l2) {
		cout<<s<<" ";
	}


	// l2.begin() +3 will not work bcoz direct access is not allowed in linked list  
	auto it = l2.begin();;
	it++;
	it++;
	l2.erase(it);


	cout<<endl;
	for(auto s: l2) {
		cout<<s<<" ";
	}

	it = l2.begin();
	it++;
	l2.insert(it , "cherry");


	cout<<endl;
	for(auto s: l2) {
		cout<<s<<" ";
	}
	cout<<endl;

	
	return 0;
}