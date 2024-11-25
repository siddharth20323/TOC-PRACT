#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isAccepted(string w)
{
    stack<char> pdStack;
    int n = w.length();
    int i = 0;

    while (i < n && w[i] != 'X')
    {
        pdStack.push(w[i]);
        i++;
    }
    if (i == n || w[i] != 'X')
    {
        return false;
    }
    i++;

    while (i < n)
    {
        if (pdStack.empty() || w[i] != pdStack.top())
        {
            return false;
        }
        pdStack.pop();
        i++;
    }
    return pdStack.empty();
}
int main()
{
    string w; 
    cout << "Enter a string: ";
    cin >> w;

    if (isAccepted(w))
    {
        cout << "String accepted (matches wXwr)" << endl;
    }
    else
    {
        cout << "String rejected (does not match wXwr)" << endl;
    }

    return 0;
}