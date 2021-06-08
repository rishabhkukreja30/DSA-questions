int minJumps(int arr[], int n) 
{ 
    // jumps[n-1] will hold the result 
    int* jumps = new int[n]; 
    int i, j; 

    if (n == 0 || arr[0] == 0) 
        return INT_MAX; 

    jumps[0] = 0; 

    // Find the minimum number of jumps to reach arr[i] 
    // from arr[0], and assign this value to jumps[i] 
    for (i = 1; i < n; i++) { 
        jumps[i] = INT_MAX; 
        for (j = 0; j < i; j++) { 
            if (i <= j + arr[j] && jumps[j] != INT_MAX) { 
                jumps[i] = min(jumps[i], jumps[j] + 1); 
                break; 
            } 
        } 
    } 
    return jumps[n - 1]; 
}

Now moving to optimised approach,basically idea is to take jump only when its needed. The variable maxReach stores at all time the maximal reachable position in the array. jump stores the amount of jumps necessary to reach that position. step stores the amount of steps we can still take (and is initialized with the amount of steps at the first array position)

During the iteration, the above values are updated as follows:

First we test whether we have reached the end of the array, in which case we just need to return the jump variable.

Next we update the maximal reachable position. This is equal to the maximum of maxReach and i+A[i] (the number of steps we can take from the current position).

We used up a step to get to the current index, so steps has to be decreased.

If no more steps are remaining (i.e. steps=0, then we must have used a jump. Therefore increase jump. Since we know that it is possible somehow to reach maxReach, we initialize the steps to the amount of steps to reach maxReach from position i.

Time Complexity : O(NN).
#include<bits/stdc++.h>
using namespace std;
#define int long long 

int MinJumpReq(vector<int> &a){
    int n=a.size();
    if(a[0]==0)return INT_MAX;
    int minJump=1;
    int maxReach=a[0],step=a[0];
    for(int i=1;i<n-1;i++){
        step--;
        maxReach=max(maxReach,i+a[i]);
        if(step==0){
            minJump++;
            if(maxReach<=i)return INT_MAX;
            step=maxReach-i;
        }
    }
    return minJump;
}


// or
int minJumps(int arr[], int n)
{
 
    // The number of jumps needed to
    // reach the starting index is 0
    if (n <= 1)
        return 0;
 
    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;
 
    // initialization
    // stores all time the maximal
    // reachable index in the array.
    int maxReach = arr[0];
 
    // stores the number of steps
    // we can still take
    int step = arr[0];
 
    // stores the number of jumps
    // necessary to reach that maximal
    // reachable position.
    int jump = 1;
 
    // Start traversing array
    int i = 1;
    for (i = 1; i < n; i++) {
        // Check if we have reached the end of the array
        if (i == n - 1)
            return jump;
 
        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);
 
        // we use a step to get to the current index
        step--;
 
        // If no further steps left
        if (step == 0) {
            // we must have used a jump
            jump++;
 
            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;
 
            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }
 
    return -1;
}




