#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void q0(string w, int i);  //even even
void q1(string w, int i);
void q2(string w, int i);
void q3(string w, int i);

void q0(string w, int i) {
    cout << "STATE q0 (Accepting)" << endl;
    if (i == w.length()) {
        cout << "String accepted: " << w << endl;
        return;
    }
    if(w[i]=='a'){
        q1(w,i+1);
    } else if(w[i]=='b'){
        q2(w,i+1);
    }
    else{
        cout << "Invalid character. String rejected." << endl;

    }
}

void q1(string w, int i) {
    cout << "STATE q1 (rejected)" << endl;
    if (i == w.length()) {
        cout << "String rejected: " << w << endl;
        return;
    }
    if(w[i]=='a'){
        q0(w,i+1);
    } else if(w[i]=='b'){
        q3(w,i+1);
    }
    else{
        cout << "Invalid character. String rejected." << endl;

    }
}


void q2(string w, int i) {
    cout << "STATE q2 (rejected)" << endl;
    if (i == w.length()) {
        cout << "String rejected: " << w << endl;
        return;
    }
    if(w[i]=='a'){
        q3(w,i+1);
    } else if(w[i]=='b'){
        q0(w,i+1);
    }
    else{
        cout << "Invalid character. String rejected." << endl;

    }
}

void q3(string w, int i) {
    cout << "STATE q3 (rejected)" << endl;
    if (i == w.length()) {
        cout << "String rejected: " << w << endl;
        return;
    }
    if(w[i]=='a'){
        q2(w,i+1);
    } else if(w[i]=='b'){
        q1(w,i+1);
    }
    else{
        cout << "Invalid character. String rejected." << endl;

    }
}

int main() {
    string w;
    cout << "Enter a string over {a, b}: ";
    cin >> w;
 
    q0(w, 0);

    return 0;
}

