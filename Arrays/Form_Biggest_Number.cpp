/*
A simple solution that comes to our mind is to sort all numbers in descending order, 
but simply sorting doesn’t work. For example, 548 is greater than 60, but in output 60 comes before 548. 
As a second example, 98 is greater than 9, but 9 comes before 98 in output.

So how do we go about it? The idea is to use any comparison based sorting algorithm. 
In the used sorting algorithm, instead of using the default comparison, 
write a comparison function myCompare() and use it to sort numbers. Given two numbers X and Y, 
how should myCompare() decide which number to put first – we compare two numbers XY (Y appended at the end of X) 
and YX (X appended at the end of Y). If XY is larger, then X should come before Y in output, 
else Y should come before. For example, let X and Y be 542 and 60. To compare X and Y, we compare 54260 and 60542. 
Since 60542 is greater than 54260, we put Y first.     */



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);

    // then append X at the end of Y
    string YX = Y.append(X);

    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}
int main(int argc, char* argv[])
{
    int t;
    int n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<string> arr;
        for(int i=0;i<n;i++) {
            string temp;
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end(), myCompare);
        for(int i=0;i<n;i++) {
            cout<<arr[i];
        }
        cout<<endl;
    }

    return 0;
}