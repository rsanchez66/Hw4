#include <iostream>
#include <cstring> 
#include <cstdlib> 

// Function to replace every occurrence of target in source with replaceText
void replaceString(char*& source, const char* target, const char* replaceText) {
    int sourceLength = strlen(source);
    int targetLength = strlen(target);
    int replaceLength = strlen(replaceText);

    // Pointer for the current occurrence of target in source
    char* targetPtr = strstr(source, target);

    while (targetPtr != nullptr) {
        // Calculate the new length of source
        int newLength = sourceLength - targetLength + replaceLength;

        // Allocate memory for the new string
        char* newSource = (char*)malloc(newLength + 1);

        // Copy characters from the beginning
        strncpy(newSource, source, targetPtr - source);
        newSource[targetPtr - source] = '\0';

    
        strcat(newSource, replaceText);

       
        strcat(newSource, targetPtr + targetLength);

        // the old source memory
        free(source);

        // Update source
        source = newSource;

        // Update sourceLength and search for the next occurrence of target
        sourceLength = newLength;
        targetPtr = strstr(source, target);
    }
}

int main() {
    char* source = strdup("abcdabee");
    const char* target = "ab";
    const char* replaceText = "xyz";

    replaceString(source, target, replaceText);

    std::cout << "Modified string: " << source << std::endl;

    free(source); // allocated memory

    return 0;
}