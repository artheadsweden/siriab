#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person() {
        name = "Hello";
        age = 99;
    }

    Person(string name) {
        this->name = name;
        age = 0;
    }

    Person(string n, int a) {
        name = n;
        age = a;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

private:
    string name;
    int age;
};

int main() {
    Person p;
    Person pp = Person("Anna");
    Person p1 = Person("John", 34);
    Person p2 = Person("Alice", 45);
    p1.setName("Pete");
    cout << pp.getName() << " " << pp.getAge() << endl;
    cout << p1.getName() << " " << p1.getAge() << endl;
    cout << p2.getName() << " " << p2.getAge() << endl;

    return 0;
}