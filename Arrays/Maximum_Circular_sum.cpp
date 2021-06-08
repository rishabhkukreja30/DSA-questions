 
#include<bits/stdc++.h>
using namespace std;
// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int a[], int n);

// The function returns maximum circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
// Case 1: get the maximum sum using standard kadane's algorithm
int max_kadane = kadane(a, n);

// Case 2: Now find the maximum sum that includes
// corner elements.
int max_wrap = 0, i;
for (i=0; i<n; i++)
{
        max_wrap += a[i];     // Calculate array-sum
        a[i] = -a[i];       // invert the array (change sign)
}

// max sum with corner elements will be:
// array-sum - (-max subarray sum of inverted array)
max_wrap = max_wrap + kadane(a, n);

// The maximum circular sum will be maximum of two sums
return (max_wrap > max_kadane)? max_wrap: max_kadane;
}

// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int a[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

/* Driver program to test maxCircularSum() */
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
       int n;
       cin>>n;
       int a[n];
       for(int j=0;j<n;j++)
       {
           cin>>a[j];
       }
        cout<< maxCircularSum(a, n) <<endl;
    }
    return 0;
}


    int kadane(vector <int> &A) {
        int curr_sum = 0;
        int max_sum = INT_MIN;
        
        for(int i=0;i<A.size();i++) {
            curr_sum += A[i];
            
            max_sum = max(max_sum, curr_sum);
            
            if(curr_sum < 0) {
                curr_sum = 0;
            }
        }
        return max_sum;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.empty()) {
            return 0;
        }
        
        int case1 = kadane(A);
        
        if(case1 < 0) {
            return case1;
        }
        
        int sum = 0;
        for(int i=0;i<A.size();i++) {
            sum += A[i];
            A[i] = -A[i];
        }
        
        int case2 = sum + kadane(A);
        
        return max(case1, case2);
        
    }


    