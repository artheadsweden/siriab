#include <iostream>

using namespace std;

void func(int& x) {
    x++;
}

void func2(const int& x) {
    cout << x << endl;
}

int main() {
    int a = 10;
    int &b = a;

    b++;

    cout << a << endl;
    cout << b << endl;

    func2(a);

    std::cout << a << std::endl;
    std::cout << b << std::endl;


    return 0;
}