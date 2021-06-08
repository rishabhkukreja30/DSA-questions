#include<bits/stdc++.h>
using namespace std;



int main() {


	int a[] = {1,3,5,7,10,11,12,13};
	int k = 16;

	int i=0;
	int j= sizeof(a)/sizeof(int) -1;

	while(i<j) {
		int current_sum = a[i]  +a[j];
		if(current_sum > k) {
			j--;
		}
		else if(current_sum <k) {
			i++;
		}
		else if(current_sum == k) {
			cout<<a[i]<<" and "<<a[j]<<endl;
			i++;
			j--;
		}
	}

	return 0;
}