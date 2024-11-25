#include <iostream>
#include <string>
using namespace std;

bool turingMachine(string tape) {
    int head = 0;    // Head position
    int state = 0;   // Initial state

    while (true) {
        if (state == 0) { // Looking for 'a'
            if (tape[head] == 'a') {
                tape[head] = 'X'; // Mark 'a' as processed
                state = 1;        // Move to find 'b'
                head++;
            } else if (tape[head] == '_') { // End of tape
                state = 4; // Accept state if all are processed
            } else {
                state = 5; // Reject for invalid input
            }
        } 
        else if (state == 1) { // Looking for 'b'
            if (tape[head] == 'b') {
                tape[head] = 'Y'; // Mark 'b' as processed
                state = 2;        // Move to find 'c'
                head++;
            } else if (tape[head] == '_') { // End of tape
                state = 5; // Reject if no 'b' found
            } else {
                head++; // Keep searching
            }
        } 
        else if (state == 2) { // Looking for 'c'
            if (tape[head] == 'c') {
                tape[head] = 'Z'; // Mark 'c' as processed
                state = 3;        // Move back to find another 'a'
                head--;
            } else if (tape[head] == '_') { // End of tape
                state = 5; // Reject if no 'c' found
            } else {
                head++; // Keep searching
            }
        } 
        else if (state == 3) { // Move left to find another 'a'
            if (tape[head] == 'X') {
                head--; // Skip processed 'a'
            } else if (tape[head] == '_') {
                head++; // Move to unprocessed part
                state = 0; // Go back to find more 'a's
            } else {
                head--; // Keep moving left
            }
        } 
        else if (state == 4) { // Accept state
            // Verify if all characters are processed
            for (char ch : tape) {
                if (ch != 'X' && ch != 'Y' && ch != 'Z' && ch != '_') {
                    return false; // Reject if any unprocessed characters remain
                }
            }
            return true;
        } 
        else if (state == 5) { // Reject state
            return false;
        }
    }
}

int main() {
    string tape;
    cout << "Enter the string (terminated with '_'): ";
    cin >> tape;

    if (turingMachine(tape)) {
        cout << "String accepted (belongs to {a^n b^n c^n | n > 0})" << endl;
    } else {
        cout << "String rejected (does not belong to {a^n b^n c^n | n > 0})" << endl;
    }

    return 0;
}
