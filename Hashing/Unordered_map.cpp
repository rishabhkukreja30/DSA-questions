#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {

	unordered_map <string, int > m;

	//insert
	m.insert(make_pair("mango", 100));

	pair <string ,int> p;
	p.first = "apple";
	p.second = 120;

	m.insert(p);

	m["banana"] = 20;

	// search
	auto it = m.find("banana");
	if(it != m.end()) {
		cout<<"Price of banana is "<<m["banana"]<<endl;
	}
	else {
		cout<<"not present"<<endl;
	}

	m.erase("mango");

	//another way
	if(m.count("mango")) {
		cout<<"Price of mango is "<<m["mango"]<<endl;
	}
	else {
		cout<<"not present"<<endl;
	}

	m["lichi"] = 60;
	m["guava"] = 45;
	m["pineapple"] = 90;

	for(auto it = m.begin();it!=m.end();it++) {
		cout<<it->first<< " and "<<it->second<<endl;
	}

	m.erase("lichi");

	for(auto p: m) {
		cout<<p.first<<" : "<<p.second<<endl;
	}

	return 0;
}