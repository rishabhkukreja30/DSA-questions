#include<bits/stdc++.h>
using namespace std;

//implement a hashmap
//separate chaining technique

template <typename t>
class node {
public:
	string key;
	t value;
	node<t>* next;

	node(string key, t val) {
		this->key = key;
		value = val;
		next = NULL;
	}
	~node() {
		if(next != NULL) {
			delete next;
		}
	}
};

template <typename t>
class hashtable {

	node<t>** table;  // pointer to an array of pointers
	int current_size;
	int table_size;

	int hashFn(string key) {
		int idx = 0;
		int p =1;
		for(int j=0;j<key.length(); j++) {
			idx = idx + (key[j] * p)%table_size;
			idx = idx%table_size;
			p = (p*27)%table_size;
		}
		return idx;
	}

	void rehash() {

		node<t>** oldtable = table;
		int oldtablesize = table_size;
		table_size = 2*table_size; // or take next prime number
		table = new node<t>*[table_size];

		for(int i=0;i<table_size;i++) {
			table[i] = NULL;
		}
		current_size = 0;

		//shift the elements from old table to new table
		for(int i=0;i<oldtablesize;i++) {
			node<t>*temp = oldtable[i];
			while(temp != NULL) {
				insert(temp->key, temp->value);
				temp = temp->next;
			}
			if(oldtable[i] != NULL) {
				delete oldtable[i];
			}
		}
		delete [] oldtable;
	}

public:
	hashtable(int ts =7) {
		table_size = ts;
		table = new node<t>*[table_size];    // student **s = new student*[10];
		current_size  =0;
		for(int i=0;i<table_size;i++) {
			table[i] = NULL;
		}
	}



	void insert(string key, t value) {
		int idx = hashFn(key);

		node<t>*n = new node<t>(key,value);
		//insert at the head of the linked list with id = idx
		n->next = table[idx];
		table[idx] = n;
		current_size++;

		//rehashing
		float load_factor = current_size / (1.0*table_size);

		if(load_factor > 0.7) {
			rehash();
		}

	}

	void print() {

		for(int i=0;i<table_size;i++) {
			cout<<"Bucket "<<i<<" -->";
			node<t>*temp = table[i];
			while(temp != NULL) {
				cout<<temp->key<<" -->";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	t* search(string key) {
		int idx = hashFn(key);
		node<t>*temp = table[idx];
		while(temp != NULL) {
			if(temp->key == key) {
				return &temp->value;
			}
			temp = temp->next;
		}
		return NULL;    // t*
	}

	void erase(string key) {

	}

	t& operator [](string key) {
		t* f = search(key);
		if(f == NULL) {
			//insert key, value(garbage) in the hashmap
			t garbage;
			insert(key, garbage);
			f = search(key);
		}
		return *f;
	}


};


int main() {

	hashtable<int> price_menu;

	price_menu.insert("Burger", 120);
	price_menu.insert("Pepsi", 20);
	price_menu.insert("Pizza", 150);
	price_menu.insert("Noodles", 25);
	price_menu.insert("Coke", 40);

	price_menu.print();

	int *price  =price_menu.search("Noodles");
	if(price == NULL) {
		cout<<"Not found"<<endl;
	}
	else {
		cout<<"Price is "<<*price<<endl;
	}

	// map

	//insert
	price_menu["Dosa"] = 60;
	//update
	price_menu["Dosa"] += 10;
	//search
	cout<<"Price of dosa ";
	cout<<price_menu["Dosa"]<<endl;



	return 0;

}