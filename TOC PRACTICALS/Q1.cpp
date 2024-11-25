#include <iostream>
#include <string>
using namespace std;

void State1(string w, int i);
void State2(string w, int i);
void State3(string w, int i);
void State4(string w, int i);


void State1(string w, int i)
{
    cout << "State 1" << endl;
    if (i == w.length())
    {
        cout << "string rejected" << endl;
        return;
    }
    else if (w[i] == '0')
    {
        State1(w, i + 1);
    }
    else if (w[i] == '1')
    {
        State2(w, i + 1);
    }
}

void State2(string w, int i)
{
    cout << "State 2" << endl;
    if (i == w.length())
    {
        cout << "string rejected" << endl;
        return;
    }
    else if (w[i] == '0')
    {
        State1(w, i + 1);
    }
    else if (w[i] == '1')
    {
        State3(w, i + 1);
    }
}

void State3(string w, int i)
{
    cout << "State 3" << endl;
    if (i == w.length())
    {
        cout << "string rejected" << endl;
        return;
    }
    else if (w[i] == '0')
    {
        State1(w, i + 1);
    }
    else if (w[i] == '1')
    {
        State4(w, i + 1);
    }
}
void State4(string w, int i)
{
    cout << "State 4" << endl;
    if (i == w.length())
    {
        cout << "string accepted" << endl;
    }
    else
    {
        State4(w, i + 1);
    }
}

int main()
{
    string w;
    cout << "Enter a binary string: ";
    cin >> w;
    State1(w, 0);
    return 0;
}
