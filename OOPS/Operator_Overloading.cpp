#include<bits/stdc++.h>
using namespace std;


class Complex {
	int real;
	int img;
public:

	Complex() {
		real = 0;
		img = 0;
	}
	//parameterized constructor
	Complex(int i,int r) {
		real = r;
		img = i;
	}
	//copy constructor
	//it exists by default

	void setReal(const int r) {
		real = r;
	}

	void setImg(const int i) {
		img = i;
	}
	int getReal() const {
		return real;
	}
	int getImg() const {
		return img;
	}

	void print() {
		if(img>0) {
			cout<<real<<" + "<<img<<"i"<<endl;
		}
		else {
			cout<<real<<" - "<<img<<"i"<<endl;
		}
	}

	void add(const Complex &x) {
		real += x.real;
		img += x.img;
	}

	void operator+(const Complex &x) {
		real += x.real;
		img += x.img;
	}
	void operator!() {
		img *= -1;
	}
	int operator[](string s) {
		//cout<<real<<" + "<<img<<s<<endl;
		if(s == "real") {
			return real;
		}
		if(s == "img") {
			return img;
		}
	}


};

// is - basically cin object passed by reference
// return type is istream to achieve cin>>d1>>d2;  - Cascading of operators
istream& operator>>(istream& is, Complex &c) {
	int r1,i1;
	is>>r1>>i1;
	c.setReal(r1);
	c.setImg(i1);
	return is;
}

ostream& operator<<(ostream& os, Complex &c)  {
	c.print();
	return os;
}


int main() {

	Complex c1(5,3);
	Complex c2;
	c2.setImg(4);
	c2.setReal(1);

	c1.print();
	c2.print();

	c1+c2;
	c1.print();

	!c1;

	c1.print();

	cout<<c1["img"];

	cout<<endl;
	Complex d;
	cin>>d;
	cout<<d;


	return 0;
}