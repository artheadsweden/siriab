#include <iostream>

using namespace std;

class Point {
public:
    // Default Contructor
    Point(): x(nullptr), y(nullptr){
        cout << "Default Constructor" << endl;
    }
    
    // Parameterized Constructor
    Point(int x, int y): x(new int(x)), y(new int(y)) {
        cout << "Parameterized Constructor" << endl;
    }

    // Copy Constructor
    Point(const Point& p): x(new int(*p.x)), y(new int(*p.y)){
        cout << "Copy Constructor" << endl;
    }    

    // Move Constructor
    Point(Point&& p): x(p.x), y(p.y){
        p.x = nullptr;
        p.y = nullptr;
        cout << "Move Constructor" << endl;
    } 

    ~Point() {
        cout << "Destructor" << endl;
        delete x;
        delete y;
    }

    // Copy assignment operator
    Point& operator=(const Point& p) {
        if (this != &p) { // Check for self-assignment
            delete x;
            delete y;
            x = new int(*p.x);
            y = new int(*p.y);
        }
        cout << "Copy Assignment Operator" << endl;
        return *this;
    }

    // Move Assignment Operator
    Point& operator=(Point&& p) {
        if (this != &p) { // Check for self-assignment
            delete x;
            delete y;
            x = p.x;
            y = p.y;
            p.x = nullptr;
            p.y = nullptr;
        }
        cout << "Move Assignment Operator" << endl;
        return *this;
    }

    // Operator +
    Point operator+(const Point& p) {
        cout << "Operator +" << endl;
        return Point(*x + *p.x, *y + *p.y);
    }


    // Friend operators
    friend Point operator+(int i, const Point& p) {
        cout << "Operator + (int, Point)" << endl;
        return Point(i + *p.x, i + *p.y);
    }

    friend ostream& operator<<(ostream& os, const Point& p) {
        if (p.x == nullptr) {
            os << "(x = nullptr,";
        }
        else{
            os << "(x = " << *p.x << ",";
        }

        if (p.y == nullptr) {
            os << " y = nullptr)";
        }
        else{
            os << " y = " << *p.y << ")";
        }
        return os;
    }

private:
    int* x;
    int* y;
};

Point getPoint() {
    Point p {1, 4};
    return p;
}

int main() {
    cout << "****** 1 *******" << endl;
    Point p1;   // Calls the Default Constructor
    cout << p1 << "!!!" << endl; // The << operator is called
    cout << "****** 2 *******" << endl;
    Point p2 {2, 3};  // Calls the Parameterized Constructor
    cout << "****** 3 *******" << endl;
    Point p3 {p2};  // Calls the Copy Constructor
    cout << "****** 4 *******" << endl;
    p1 = p2;  // Copy Assignment Operator
    cout << "****** 5 *******" << endl;
    p1 = p2 + p3; // Operator +, Parameterized Constructor, Move Assignment Operator, destructor
    cout << "****** 6 *******" << endl;
    p2 = getPoint(); // Parameterized Constructor, Move Assignment Operator and Destructor
    cout << "****** 7 *******" << endl;
    Point p5 = move(p1);  // Move Constructor
    cout << "****** 8 *******" << endl;
    p5 = 3 + p2; // Operator + (int, Point), Parameterized Constructor, Move Assignment Operator, Destructor
    cout << "****** 9 *******" << endl;
    cout << "c5 is " << p5 << endl;  // The << operator is called
    cout << "****** 10 ******" << endl;

    return 0;
}