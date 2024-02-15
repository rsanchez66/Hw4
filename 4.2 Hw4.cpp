#include <iostream>
#include <cstring> 

char* substring(const char* arrayString, int startPos, int length) {
    int originalLength = strlen(arrayString);
    if (startPos < 0 || startPos >= originalLength || length <= 0) {
        return nullptr; // Invalid input
    }

    // Adjust length if it exceeds the length of remaining characters
    length = std::min(length, originalLength - startPos);

    char* result = new char[length + 1]; // allocate memory for the substring
    strncpy(result, arrayString + startPos, length); // Copy substring
    result[length] = '\0'; // Null-terminate the string

    return result;
}

int main() {
    const char* originalString = "abcdefg";
    int startPos = 2;
    int length = 3;

    char* newString = substring(originalString, startPos, length);
    if (newString != nullptr) {
        std::cout << "Substring: " << newString << std::endl;
        delete[] newString; // allocated memory
    } else {
        std::cout << "Invalid parameters for substring operation." << std::endl;
    }

    return 0;
}