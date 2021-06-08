#include<bits/stdc++.h>
using namespace std;

void printSpan(int a[], int n) {
	stack <int> s;
	int ans[100];

	for(int day =0;day<n;day++) {
		int price = a[day];
		while(s.empty() == false && a[s.top()] < price) {
			s.pop();
		}

		int betterDay = s.empty() ? 0 : s.top();
		int span = day - betterDay;
		ans[day] = span;
		s.push(day);
	}

	for(int i=0;i<n;i++) {
		cout<<ans[i]<<" ";
	}
}

int main() {

	int arr[] = {100,80,60,70,60,75,85};

	int n = sizeof(arr) /sizeof(int);

	printSpan(arr, n);

	return 0;
}



