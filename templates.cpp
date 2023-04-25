#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename U>
auto add(T a, U b) {
    return a + b;
}


int main() {
    vector<int> v {1, 2, 3, 4};

    for(auto& value : v) {
        value++;
    }
    
    for(auto value : v) {
        cout << value << endl;
    }

    cout << add(1, 2) << endl;
    cout << add(1.3, 2.2) << endl;
    cout << add(1, 2.2) << endl;
    cout << add(2.2, 1) << endl;

    return 0;
}