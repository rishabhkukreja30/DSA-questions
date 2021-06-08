#include<bits/stdc++.h>
using namespace std;

class student {
public:
	string firstname;
	string lastname;
	string rollno;

	student(string f, string l , string no) {
		firstname = f;
		lastname = l;
		rollno = no;
	}


	bool operator==(const student &s)const {
		return rollno == s.rollno;
	}

};

class hashFn{
public:
	size_t operator()(const student &s)const {
		return s.firstname.length() + s.lastname.length();
	}
};



int main() {

	unordered_map  <student, int, hashFn> student_map;


	student s1("Rishabh", "Kukreja", "010");
	student s2("Rahul", "Kumar", "023");
	student s3("Rishabh", "Gupta", "030");
	student s4("Rahul", "Kumar", "120");

	//add students to hashmap
	student_map[s1] = 100;
	student_map[s2] = 120;
	student_map[s3] = 11;
	student_map[s4] = 45;

	//find the marks of student s3
	cout<<student_map[s3]<<endl;

	for(auto s:student_map) {
		cout<<s.first.firstname<<" "<<s.first.rollno<<" marks: "<<s.second<<endl;
	}



	return 0;
}