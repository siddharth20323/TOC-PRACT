#include <iostream>
#include <string>
using namespace std;

// Function to simulate the FA
bool simulateFA(const string &input) {
    int n = input.length();
    if (n < 4) {
        return false; // Length constraint
    }

    // Extract first two and last two characters
    string firstTwo = input.substr(0, 2);         // First two characters
    string lastTwo = input.substr(n - 2, 2);     // Last two characters

    // Check if first two characters match the last two characters
    return firstTwo == lastTwo;
}

int main() {
    string input;
    cout << "Enter a string over {a, b}: ";
    cin >> input;

    // Validate the string using the FA simulation
    if (simulateFA(input)) {
        cout << "Accepted: The string belongs to the language L1." << endl;
    } else {
        cout << "Rejected: The string does not belong to the language L1." << endl;
    }

    return 0;
}
