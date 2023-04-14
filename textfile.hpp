#pragma once

#include <iostream>
#include <fstream>
#include <string>


class TextFile {
public:
    // Constructor that opens the file
    TextFile(const std::string& filename, std::ios_base::openmode mode): 
        file(filename, mode), filename(filename) {
            if (!file) {
                throw std::runtime_error("Error opening file: " + filename);
            }
            std::cout << "Opening file " << filename << std::endl;
        }

    ~TextFile() {
        file.close();
        std::cout << "File closed: " << filename << std::endl;
    }

    bool readLine(std::string& line) {
        return static_cast<bool>(std::getline(file, line));
    }

    void writeLine(const std::string line) {
        file << line << std::endl;
    }

private:
    std::fstream file;
    std::string filename;
};