#include <iostream>

using namespace std;


void func(int& a) {
    cout << "a is a lvalue" << endl;
}


void func(int&& a) {
    cout << "a is a rvalue" << endl;
}


int main() {
    int x = 10;
    func(x);
    func(10);

    cout << x << endl;
    return 0;
}