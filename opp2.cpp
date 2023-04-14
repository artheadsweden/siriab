#include <iostream>
#include <string>

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

    Checker *c = new Checker("One");
    std::cout << "Done" << std::endl;
    delete c;
    
    
    return 0;
}