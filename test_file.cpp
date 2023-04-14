#include <iostream>
#include "textfile.hpp"
using namespace std;

int main() {
    try {
        TextFile inputFile("input.txt", ios_base::in);
        TextFile outputFile("output.txt", ios_base::out);

        string line;

        while(inputFile.readLine(line)) {
            outputFile.writeLine(line);
        }

    }
    catch (const runtime_error& error) {
        cerr << "Error: " << error.what() << endl;
    }
    cout << "Done" << endl;
    return 0;
}