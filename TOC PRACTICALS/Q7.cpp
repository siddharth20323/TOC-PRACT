#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isaccepted(string w)
{
    stack<char> pdStack;
    int n = w.length();

    int i = 0;
    while (i < n && w[i] == 'a')  // push a
    {
        pdStack.push('a');
        i++;
    }

    while (i < n && w[i] == 'b') // processing b and pop
    {
        if (pdStack.empty())
        {
            return false;
        }
        pdStack.pop();
        i++;
    }
    if (i == n && pdStack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string w;
    cout << "Enter a string: ";
    cin >> w;

    if (isaccepted(w))
    {
        cout << "String accepted (matches a^n b^n)" << endl;
    }
    else
    {
        cout << "String rejected (does not match a^n b^n)" << endl;
    }

    return 0;
}
