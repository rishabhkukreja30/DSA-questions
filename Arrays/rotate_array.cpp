#include <iostream>
using namespace std;

void rotate_array_by_one(int a[], int n )
{
          int temp = a[0], i;
        for (i = 0; i < n - 1; i++)
            a[i] = a[i + 1];
        a[i] = temp;
}

void rotate_array(int a[] , int d, int n)
{
        for(int j =0;j<d;j++)
            rotate_array_by_one(a,n);
}
int main() {
	//code
	int t ,n, d;
	cin>>t;
	while(t--)
	{
	    cin>>n>>d;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
        	rotate_array(a ,d ,n);
        for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	        cout<<endl;

	}
	return 0;

}
