#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

void fileRead(vector<string> &v, ifstream &fin) {
    string line;
    while(getline(fin, line))
        v.push_back(line);
}

void search(vector<string> &v, string t) {
    for(int i = 0; i < v.size(); i++) {
        int pos = v[i].find(t);
        if(pos == 0)
            cout << v[i] << endl;
    }
}

int main() {
    vector<string> word;
    ifstream fin("C:\\Coding Data\\raylib\\local_repo\\cpp_221205\\res\\words.txt");
    if(!fin) {
        cout << "file not found" << endl;
        return 0;
    }
    fileRead(word, fin);
    fin.close();

    while(true) {
        string target;
        cout << "input something word: ";
        cin >> target;
        if(target=="exit") break;
        search(word, target);
    }
}

/* bool fileCompare(const char* fa, const char* fb) {
    ifstream first  (fa, ios::in | ios::binary);
    ifstream second (fb, ios::in | ios::binary);
    if(!first || !second) {
        cout << "file not found!" << endl;
        exit(1);
    }

    int a, b;
    while((a=first.get()) != EOF || (b=second.get()) != EOF) {
        if(a!=b) {
            first.close();
            second.close();
            return false;
        }
    }
    b = second.get();
    if(b != EOF) {
        first.close();
        second.close();
        return false;
    }
    else 
        first.close();
        second.close();
        return true;
}

int main() {

    cout << boolalpha <<fileCompare("C:/Coding Data/raylib/local_repo/cpp_221205/res/let me in.gif",
                                    "C:/Coding Data/raylib/local_repo/cpp_221205/src/letMeIn.gif" );

} */

/* int main() {

    ifstream fin("C:/Coding Data/raylib/local_repo/cpp_221205/res/let me in.gif", ios::in | ios::binary);

    if(!fin) {
        cout << "Alert: file not found!" << endl;
        return 0;
    }

    ofstream fout("C:/Coding Data/raylib/local_repo/cpp_221205/src/letMeIn.gif", ios::out | ios::binary);
    if(!fout) {
        cout << "Alert: not allow this file!" << endl;
        return 0;
    }

    char buf[1024];

    while(!fin.eof()) {
        fin.read(buf, 1024);
        int n = fin.gcount();
        fout.write(buf, n);
    }

    fin.close();
    fout.close();

} */
/*
//  ifstream fin("C:/Coding Data/raylib/local_repo/cpp_221205/res/test.txt");
//  ifstream fin("C:/windows/system.ini");
//  ofstream fout("C:/Coding Data/raylib/local_repo/cpp_221205/res/windows.txt");
/*     int n;
    while((n=fin.get()) != EOF) {
        fout.put(n);
    } */

/*     string l;
    int n = 1;
    while(getline(fin, l)) {
        cout << n++ << ": " << l << endl;
    } */

/*     int n;
    while((n=fin.get()) != EOF) {
        cout.put(n);
    } */
//fout.close();
/*     string l;
    while(getline(fin, l)) {
        int i = l.find("<<");
        if(i != -1) {
            l.erase();
        } else {
            cout << l << endl;
        }
    } */
/**/