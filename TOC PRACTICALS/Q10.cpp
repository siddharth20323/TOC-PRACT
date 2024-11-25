#include <iostream>
#include <string>
using namespace std;

string turingMachine(string tape)
{
    int head = tape.length() - 2; // Start before the delimiter '_'
    int state = 0;

    while (true)
    {
        if (state == 0)
        {
            if (tape[head] == '1')
            {
                tape[head] = '0';
                head--;
            }
            else if (tape[head] == '0')
            {
                tape[head] = '1';
                state = 1;
            }
            else if (tape[head] == '_')
            {
                tape = '1' + tape;
                state = 1;
            }
        }
        else if (state == 1)
        {
            return tape;
        }
    }
}
int main()
{
    string tape;
    cout << "Enter a binary number terminated with '_': ";
    cin >> tape;

    // Validate the input
    for (char ch : tape)
    {
        if (ch != '0' && ch != '1' && ch != '_')
        {
            cout << "Invalid input. Tape must contain only binary digits followed by '_'.\n";
            return 1;
        }
    }

    string result = turingMachine(tape);
    cout << "Result after incrementing: " << result << endl;

    return 0;
}
