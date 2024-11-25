#include <iostream>
#include <string>
using namespace std;

 
void q0(string w, int i);
void q1(string w, int i);
void q2(string w);
void trap();

void q0(string w, int i){
    cout<<"state 0<<endl";
    if(i==w.length()){
        cout << "String rejected (must start with 'a')" << endl;
        return;
    }
    if(w[i]=='a'){
        q1(w,i+1);
    }else{
        trap();
    }
}

void q1(string w, int i) {
    cout << "STATE 1" << endl;
    if (i == w.length()) {
        cout << "String rejected (must end with 'b')" << endl;
        return;
    }

    if(w[i]=='a' || w[i]=='b'){
        if(i==w.length()-1 && w[i]=='b'){
            q2(w);
        } else{
            q1(w,i+1);
        }
    } else{
        trap();
    }
}

void q2(string w) {
    cout << "STATE 2 (Accepted)" << endl;
    cout << "String accepted: " << w << endl;
}

void trap() {
    cout << "TRAP STATE (Rejected)" << endl;
    cout << "String rejected due to invalid transition" << endl;
}

int main() {
    string w;
    cout << "Enter a string: ";
    cin >> w;

    if (w.empty()) {
        cout << "String rejected (empty string)" << endl;
    } else {
        q0(w, 0);
    }
    return 0;
}