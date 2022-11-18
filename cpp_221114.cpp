/**
 * @file test.cpp
 * @author minsu bak (minsu5875@naver.com)
 * @brief cpp training lecture
 * @version null
 * @date 2022-11-14
 * 
 * @copyright Copyright (c) 2022
 * 
 * g++ [filename.cpp] -o [filename] && ./[filename.exe]
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 1) {this->radius = radius;}
    int getRadius() {return radius;}
};

// template <class T>
/*8**********************************************************************/

void printVec(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

double getAvg(vector<int> v) {
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
        sum += v[i];
    return double(sum)/v.size();
}

int main() {
    vector<int> v;
    while(true) {
        cout << "entered the number (exit when input 0)>> ";
        int num;
        cin >> num;
        if(num == 0) return 0;

        v.push_back(num);
        printVec(v);
        cout << "Average = " << getAvg(v) << endl;
    }
}

/*7**********************************************************************/
/*
T bigger(T a, T b) {
    if(a > b) return a;
    else return b;
}

Circle bigger(Circle a, Circle b) {
    if(a.getRadius() > b.getRadius()) return a;
    else return b;
}

int main() {
    int a = 20, b = 50, c;
    c = bigger(a, b);
    Circle waffle(10), pizza(20), y;
    y = bigger(waffle, pizza);

    cout << c << endl;
    cout << y.getRadius() << endl;
}
*/
/*6**********************************************************************/
/*
T *remove(T a[], int sizeA, T b[], int sizeB, int& retSize) {
    T* result = new T[sizeA];

    int k = 0;
    for(int i = 0; i < sizeA; i++) {
        int j;
        for(j = 0; j < sizeB; j++)
            if(a[i] == b[j])
                break;
        
        if(j == sizeB)
            result[k++] = a[i];
    }
    retSize = k;
    if( k == 0 ) {
        delete [] result;
        return NULL;   
    }

    T *p = result;
    if(sizeA != retSize) {
        p = new T[k];
        for(int i = 0; i < k; i++)
            p[i] = result[i];
        delete[] result;
    }
    return p;
}

int main() {
    int x[] = {1,2,3,4};
    int y[] = {-3, 5, 10, 1};

    int retSize;
    int *p = remove(x, 4, y, 5, retSize);
    if(retSize == 0) cout << "result is blank " << endl;
    else {
        for(int i = 0; i < retSize; i++) {
            cout << p[i] << " ";

        }
    }
}
*/
/*5**********************************************************************/
/*
T* concat(T *a, int sizeA, T *b, int sizeB) {
    T *result = new T[sizeA + sizeB];
    for(int i = 0; i < sizeA; i++)
        result[i] = a[i];
    for(int i = 0; i < sizeB; i++)
        result[i + sizeA] = b[i];
    return result;
}

int main() {
    int x[] = {1, 100, 10, 4, 5};
    int y[] = {3, 9, 8};

    int *p = concat(x, 5, y, 3);

    for(int i = 0; i < 8; i++) cout << p[i] << " ";
    cout << endl;
}
*/
/*4**********************************************************************/
/*
bool search(T item, T *p, int n) {
    for (int i = 0; i < n; i++) {
        if(p[i] == item)
            return true;
    }
    return false;
}

int main() {
    int x[] = {1, 100, 10, 4, 5};
    double p[] = {2.4, 4.5, 6.7, 5.1, 6.3};

    if(search(101, x, 5)) cout << "exist" << endl;
    else cout << "not found" << endl;

    if(search(4.5, p, 5)) cout << "exist" << endl;
    else cout << "not found" << endl;
}
*/
/*3**********************************************************************/
/*
void reverseArray(T *p, int n) {
    for(int i=0; i< n/2; i++) {
        T tmp = p[i];
        p[i] = p[n-i-1];
        p[n-i-1] = tmp;
    }
}

int main() {
    int x[] = {1, 100, 10, 4, 5};
    double p[] = {2.4, 4.5, 6.7, 5.1, 6.3};

    reverseArray(x, 5);
    reverseArray(p, 5);

    for(int i = 0; i < 5; i++) cout << x[i] << " ";
    cout << endl;
    for(int i = 0; i < 5; i++) cout << p[i] << " ";
}
*/
/*2**********************************************************************/
/*
bool equlArrays(T *a, T *b, int n) {
    for(int i = 0; i < n; i++)
        if(a[i]!=b[i]) return false;
    return true;
}

int main() {
    int x[] = {1, 100, 10, 4, 5};
    int y[] = {1, 100, 10, 4, 5};
    int z[] = {10, 100, 10, 4, 5};

    if(equlArrays(x, y, 5)) cout << "same" << endl;
    else cout << "diffirent" << endl;

    if(equlArrays(x, z, 5)) cout << "same" << endl;
    else cout << "diffirent" << endl;

    double p[] = {2.4, 4.5, 6.7};
    double q[] = {2.4, 4.5, 6.7};

    if(equlArrays(p, q, 3)) cout << "same" << endl;
    else cout << "diffirent" << endl;
}
*/
/*1**********************************************************************/
/*
T biggest(T a[], int n) {
    T max = a[0];
    for(int i = 0; i < n; i ++)
        if(max < a[i])
            max = a[i];
    return max;
}

int main() {
    int x[] = {1, 100, 10, 4, 5};
    cout << biggest(x, 5) << endl;

    double y[] = {7.5, 9.4, 11.2, 45.6, 23.7};
    cout << biggest(y, 5) << endl;
}
*/