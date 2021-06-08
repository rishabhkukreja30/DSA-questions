#include<bits/stdc++.h>
using namespace std;



int main() {

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	priority_queue <int> leftheap;   // max heap
	priority_queue <int ,vector <int>, greater <int> > rightheap;   //min heap

	int d;
	cin>>d;
	leftheap.push(d);

	float med  = d;
	cout<<med<<" ";

	//input all elements

	while(d!= -1) {
		//logic

		if(leftheap.size() > rightheap.size()) {
			if(d < med) {
				rightheap.push(leftheap.top());
				leftheap.pop();
				leftheap.push(d);
			}
			else {
				rightheap.push(d);
			}
			med = (leftheap.top() + rightheap.top()) / 2.0;
		}
		else if(leftheap.size() == rightheap.size()) {
			if(d < med) {
				leftheap.push(d);
				med = leftheap.top();
			}
			else {
				rightheap.push(d);
				med = rightheap.top();
			}
		}
		else {
			if(d >med) {
				leftheap.push(rightheap.top());
				rightheap.pop();
				rightheap.push(d);
			}
			else {
				leftheap.push(d);
			}
			med = (leftheap.top() + rightheap.top()) / 2.0;
		}

		cout<<med<<" ";
		cin>>d;

	}




	return 0;

}
