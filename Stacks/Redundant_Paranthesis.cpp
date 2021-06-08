
#include <iostream>
#include <stack>
using namespace std;

// Function to find duplicate parenthesis in a
// balanced expression
bool findDuplicateparenthesis(string str)
{
    // create a stack of characters
    stack<char> Stack;

    // Iterate through the given expression
    for (char ch : str)
    {
        // if current character is close parenthesis ')'
        if (ch == ')')
        {
            // pop character from the stack
            char top = Stack.top();
            Stack.pop();

            // if immediate pop is a open parenthesis '(',
            // we have found duplicate
            if (top == '(')
                return true;

            // else we continue popping characters from the
            // stack till open parenthesis '(' is encountered
            else
            {
                while (top != '(')
                {
                    top = Stack.top();
                    Stack.pop();
                }
            }
        }

        // push open parenthesis '(', operators and
        // operands to stack
        else
            Stack.push(ch);
    }

    // No duplicates found
    return false;
}

// Driver code
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string str;
        cin>>str;
        if (findDuplicateparenthesis(str))
        cout << "Duplicate"<<endl;
       else
        cout << "Not Duplicates"<<endl;
    }

    return 0;
}





