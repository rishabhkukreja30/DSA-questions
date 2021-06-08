#include<bits/stdc++.h>
using namespace std;

// when to use private and public:
// when you do not want to give access to the variable outside the class , make it private
// then you can access  this variable by making a function in public and initializing the variable acc. to some logic
class car {
	int price;
public:
	
	int model_no;
	char name[20];

	// setters - to access a private member and set its value
	void set_price(int p) {
		price = p;
	}
	// getters - to get a private number
	int get_price() {
		return price;
	}

};

int main()  {

	//car arr[20]; // store info of 20 cars;

	car c;

	cout<<sizeof(c)<<endl;
	cout<<sizeof(car)<<endl;

	c.price = 100;
	c.model_no = 1;
	c.name[0] = 'a';
	c.name[1] = 'u';
	c.name[2] = 'd';
	c.name[3] = 'i';
	c.name[4] = '\0';

	cout<<c.name<<" "c<<.price<<" "<<c.model_no<<endl;





	return 0;
}