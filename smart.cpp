#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Checker{
public:
    Checker(string name): name(name) {
        cout << "Constructing object " << name << endl;
    }

    ~Checker() {
        cout << "Destructing object " << name << endl;
    }

private:
    string name;
};


int main() {
    cout << "Before" << endl;
    {
        unique_ptr<Checker> p1 {new Checker("One")};
        cout << "After" << endl;
    }
    return 0;
}