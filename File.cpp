#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <unordered_map>

void replaceDigitsAndPrint(const std::string& inputFileName) {
    std::unordered_map<char, std::string> digitMap = {
        {'0', "zero"}, {'1', "one"}, {'2', "two"}, {'3', "three"}, {'4', "four"},
        {'5', "five"}, {'6', "six"}, {'7', "seven"}, {'8', "eight"}, {'9', "nine"}
    };

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file for reading: " << inputFileName << std::endl;
        return;
    }

    std::string line;
    bool newSentence = false;

    while (std::getline(inputFile, line)) {
        std::ostringstream processedLine;

        for (size_t i = 0; i < line.size(); ++i) {
            char ch = line[i];

            // If the character is a digit, replace it with the corresponding word
            if (digitMap.count(ch)) {
                processedLine << digitMap[ch];
            } 
            else {
                processedLine << ch;
            }

            // Check if the character ends a sentence
            if (ch == '.' || ch == '!' || ch == '?') {
                newSentence = true;
            } else if (newSentence ) {
                // Add a new line only at the start of a new sentence
                if (processedLine.tellp() > 0) {
                    processedLine << "\n";
                }
                newSentence = false;
            }
            
        }

        std::cout << processedLine.str() << std::endl;
    }

    inputFile.close();
}

int main() {
    std::string inputFileName;

    std::cout << "Enter the name of the file to process: ";
    std::cin >> inputFileName;

    replaceDigitsAndPrint(inputFileName);

    return 0;
}