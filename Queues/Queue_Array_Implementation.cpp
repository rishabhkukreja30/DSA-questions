#include<bits/stdc++.h>
using namespace std;

class Queue {

	int *arr;
	int Front , rear, current_size , max_size;

public:
	Queue(int ds = 5) {
		arr = new int[ds];
		current_size = 0;
		max_size = ds;
		Front = 0;
		rear = max_size - 1;
	}

	bool full() {
		return current_size == max_size;
	}

	bool  empty() {
		return current_size == 0;
	}

	void push(int data) {
		if(!full()) {
			rear = (rear + 1) % max_size;
			arr[rear] = data;
			current_size++;
		}
	}

	void pop() {
		if(!empty()) {
			Front = (Front +1) % max_size;
			current_size--;
		}
	}

	int front() {
		return arr[Front];
	}

	~Queue() {
		if(arr != NULL) {
			delete [] arr;
			arr = NULL;
		}

	}


};



int main() {

	Queue q(100);

	for(int i=1;i<=6;i++) {
		q.push(i);
	}

	q.pop();
	q.pop();
	q.push(7);

	while(!q.empty()) {
		cout<<q.front()<<" ";
		q.pop();
	}


	return 0;
}




