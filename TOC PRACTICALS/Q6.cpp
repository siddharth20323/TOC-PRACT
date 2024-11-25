#include <iostream>
#include <string>
using namespace std;

bool st1(string w)
{
    int n = w.length();
    if (n < 4)
    {
        return false;
    }
    return w[0] == w[n - 2] && w[1] == w[n - 1];
}

bool st2(string w)
{
    int n = w.length();
    if (n < 2 || w[0] != 'a' || w[n - 1] != 'b')
    {
        return false;
    }
    return true;
}

bool unionFA(string w)
{
    return st1(w) || st2(w);
}

bool intersectionFA(string w)
{
    return st1(w) && st2(w);
}

bool concatenationFA(string w)
{
    int len = w.length();
    for (int i = 1; i < len; i++)
    {
        string pt1 = w.substr(0, i);
        string pt2 = w.substr(i);
        if (st1(pt1) && st2(pt2))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string w;
    cout << "Enter a string: ";
    cin >> w;

    // Union
    if (unionFA(w))
    {
        cout << "String accepted by Union (L1 ∪ L2)" << endl;
    }
    else
    {
        cout << "String rejected by Union (L1 ∪ L2)" << endl;
    }

    // Intersection
    if (intersectionFA(w))
    {
        cout << "String accepted by Intersection (L1 ∩ L2)" << endl;
    }
    else
    {
        cout << "String rejected by Intersection (L1 ∩ L2)" << endl;
    }

    // Concatenation
    if (concatenationFA(w))
    {
        cout << "String accepted by Concatenation (L1 L2)" << endl;
    }
    else
    {
        cout << "String rejected by Concatenation (L1 L2)" << endl;
    }
    return 0;
}
