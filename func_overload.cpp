#include <iostream>

using namespace std;

int add(int a, int b) {
    cout << "int add" << endl;
    return a + b;
}

double add(double a, double b) {
    cout << "double add" << endl;
    return a + b;
}

int main() {
    add(1, 2);
    add(1.3, 1.4);
    return 0;
}