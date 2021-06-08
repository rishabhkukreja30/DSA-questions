#include<bit/stdc++.h>
using namespace std;

template <typename T> 
class Stack {
	queue <T> q1, q2;

public:
	void push(T x) {
		q1.push(x);
	}
	void pop() {
		// remove the last added element in q1
		// we have to move first n-1 elements in q2
		// interchange names of q1 and q2
		if(q1.empty()) {
			return;
		}
		while(q1.size() > 1) {
			T element = q1.front();
			q2.push(element);
			q1.pop();
		}
		//removes the last element
		q1.pop();

		//swap thr names of q1 and q2
		swap(q1,q2);
	}
	T top() {

		while(q1.size() >1 ) {
			T element = q1.front();
			q2.push(element);
			q1.pop();
		}
		// 1 element in q1
		T element = q1.front();
		q1.pop();
		q2.push(element);

		swap(q1,q2);
	}

	int size() {
		return q1.size() + q2.size();
	}

	bool empty() {
		return size() == 0;
	}
}


int main() {










	return 0;
}