/* #include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std; */

//No.11
/* istream& pos(istream& ins) {cout << "position? "; return ins;}
int main() {
    int x, y;
    cin >> pos >> x;
    cin >> pos >> y;
    cout << x << ', ' << y << endl;
} */

//No.10
/* istream& prompt(istream& ins) {cout << "password: "; return ins;}

int main() {
    string pw;
    while(true) {
        cin >> prompt >> pw;
        if(pw == "C++") {
            cout << "login success!!" << endl;
            break;
        } else cout << "login fail. try again!" << endl;
    }
} */

//No.8
/* class Circle {
    string name;
    int radius;
public:
    Circle(int radius=1, string name="") {
        this->name = name;
        this->radius = radius;
    }
    friend ostream& operator << (ostream& outs, Circle c);
    friend istream& operator >> (istream& ins, Circle& c);
};

ostream& operator << (ostream& outs, Circle c) {
    outs << c.name <<", radius: " << c.radius << endl;
    return outs;
}

istream& operator >> (istream& ins, Circle& c) {
    cout << "radius >> ";
    ins >> c.radius;
    cout << "name   >> ";
    ins >> c.name;
    return ins;
}

int main() {
    Circle d, w;
    cin >> d >> w;
    cout << d << w;
} */

//No.7
/* int main() {
    for(int i = 0; i < 4; i++)
        cout << "dec\thexa\tchar\t";
    cout << endl;
    for(int i = 0; i < 4; i++)
        cout << "---\t----\t----\t";
    cout << endl;
    for(int i = 0; i < 128; i++) {
        cout << dec << i << '\t' << hex << i << '\t' << (isprint(i)?(char)i:'.') << '\t';
        if(i % 4 == 3)
            cout << endl;
    }
} */

//No.6
/* int main() {

    cout << left;
    cout << setw(15) << "Number" << setw(15) << "Square" << setw(15) << "Square Root" << setw(15) << endl;
    for(int i = 0; i < 50; i+=5) {
        cout << setw(15) << setfill('_') << i;
        cout << setw(15) << setfill('_') << i * i;
        cout << setw(15) << setfill('_') << sqrt((double)i) << endl;
    }
} */

//No.5
/* int main() {
    string cmd;
    cout << "read string by getline(cin, cmd) function" << endl;
    while(true) {
        cout << "enter the exit if you want >> ";
        getline(cin, cmd);
        if(cmd == "exit") {
            cout << "system shutdown";
            return 0;
        }
    }
} */

//No.4
/* int main() {
    int n;
    while((n = cin.get()) != EOF) {
        if(n == ';') {
            cin.ignore(100, '\n');
            cout << endl;
        }
        else
            cout << (char)n;
    }
} */

//No.3
/* int main() {
    int n;
    cin.ignore(100, ';');
    while((n = cin.get()) != EOF) {
        cout << (char)n;
        if(n == '\n')
            cin.ignore(100, ';');
    }
} */

//No.2
/* int main() {
    int count = 0;
    char ch;
    while(true) {
        cin.get(ch);
        if(cin.eof()) break;
        else if(ch == ' ') count++;
        else if(ch =='\n') break;
    }
    cout << "blank: " << count << endl;
} */