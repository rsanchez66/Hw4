#include <iostream>
#include <cstdlib> 

struct MyString {
    char* location;
};

void append(MyString& str, char ch) {
    
    int newSize = str.location[0] + 1;
    char* newArray = (char*)realloc(str.location, newSize + 1); // +1 for the size information
    if (newArray == nullptr) {
        std::cerr << "Memory reallocation failed." << std::endl;
        return;
    }
    str.location = newArray;

    // New character
    str.location[newSize] = ch;
    str.location[0] = newSize; // Update the size
    str.location[newSize + 1] = '\0'; // Null-terminate the string
}

void concatenate(MyString& str1, const MyString& str2) {
    // Resize str1 to accommodate the characters of str2
    int newSize = str1.location[0] + str2.location[0] - 1; // -1 for excluding the size of str2
    char* newArray = (char*)realloc(str1.location, newSize + 1); // +1 for the size
    if (newArray == nullptr) {
        std::cerr << "Memory reallocation failed." << std::endl;
        return;
    }
    str1.location = newArray;

    // str2 to str1
    for (int i = 1; i <= str2.location[0]; ++i) {
        str1.location[str1.location[0] + i - 1] = str2.location[i];
    }
    str1.location[0] = newSize; // Update the size
    str1.location[newSize + 1] = '\0'; // Null-terminate the string
}

char charAt(const MyString& str, int index) {
    if (index >= 0 && index < str.location[0] - 1) {
        return str.location[index + 1]; // +1 to skip the size
    } else {
        std::cerr << "Index out of bounds." << std::endl;
        return '\0'; // Return null character
    }
}

void display(const MyString& str) {
    // Display the characters of the string
    for (int i = 1; i <= str.location[0]; ++i) {
        std::cout << str.location[i];
    }
    std::cout << std::endl;
}

int main() {
    MyString str1;
    str1.location = (char*)malloc(2); // Allocate memory for size and null character
    str1.location[0] = 1; // Initialize size to 1
    str1.location[1] = '\0'; // Null-terminate the string

    append(str1, 'a');
    append(str1, 'b');
    display(str1); // Output: "ab"

    MyString str2;
    str2.location = (char*)malloc(3); // Allocate memory for size and null character
    str2.location[0] = 2; // Initialize size to 2
    str2.location[1] = 'c';
    str2.location[2] = 'd';
    str2.location[3] = '\0'; // Null-terminate

    concatenate(str1, str2);
    display(str1); // Output: "abcd"

    std::cout << "Character at index 2: " << charAt(str1, 2) << std::endl; // Output: "c"

    free(str1.location);
    free(str2.location);

    return 0;
}