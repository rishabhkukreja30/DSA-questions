#include<bits/stdc++.h>
using namespace std;


class car {

private:
	float price;
public:
	char *name;
	int model_no;
	const int msp;

	// initialization list
	car():msp(99) {
		name = NULL;
	}
	car(float p, int m, char *n, int minprice = 99): price(p) , msp(minprice){
		price = p;
		model_no = m;
		name = new char [strlen(n)+1];
		strcpy(name, n);
	}

	car (car &x): msp(x.msp) {
		cout<<"Inside copy constructor"<<endl;
		price = x.price;
		model_no = x.model_no;
		// deep copy
		name = new char[strlen(x.name)+1];
		strcpy(name,x.name);
	}

	void operator=(car &x) {
		price = x.price;
		model_no = x.model_no;
		// deep copy
		name = new char[strlen(x.name)+1];
		strcpy(name,x.name);
	}

	void set_price(float p) {
		price = p;
	}

	void print() {
		cout<<"Name "<<name<<endl;
		cout<<"Model no "<<model_no<<endl;
		cout<<"Price "<<price<<endl;

	}

	~car() {
		cout<<"Destroying car"<<name<<endl;
		if(name != NULL) {
			delete [] name;
		}
	}
};


int main()  {


	car c(100,200,"BMW"); // parameterized constructor
	car d(c);              // copy constructor

	car e;
	e =c;  // copy assignment operator
	cout<<c.msp<<endl;

	d.set_price(400);
	d.name[0] = 'A';

	c.print();
	d.print();
	e.print();

	// dynamically created car
	car *f = new car(10,20,"Audi");

	f->print();

	//delete keyword to delete these objects
	delete f;








	return 0;
}