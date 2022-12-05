#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream fin("C:/Coding Data/raylib/local_repo/cpp_221205/src/test.cpp");

    if(!fin) {
        cout << "Alert: file not found!" << endl;
        return 0;
    } 

    string l;
    while(getline(fin, l)) {
        int i = l.find("<<");
        if(i != -1) {
            l.erase();
        } else {
            cout << l << endl;
        }
    }


    fin.close();

}
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
/**/