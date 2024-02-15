#include <iostream>

// Define the structure for a single node
struct Node {
    char data;
    Node* next;
};

// Define the structure for our string
struct MyString {
    Node* head; 
};

// Function to append a character to the end of the string
void append(MyString& str, char ch) {
    
    Node* newNode = new Node{ch, nullptr};

    // If the string is empty, set the new node as the head
    if (str.head == nullptr) {
        str.head = newNode;
    } else {
        
        Node* current = str.head;
        while (current->next != nullptr) {
            current = current->next;
        }
        // Append the new node to the end of the list
        current->next = newNode;
    }
}

// Two strings represented as linked lists
void concatenate(MyString& s1, const MyString& s2) {
    // If s2 is empty, return 
    if (s2.head == nullptr) {
        return;
    }

    // Copy each node of s2 and append to s1
    Node* current = s2.head;
    while (current != nullptr) {
        append(s1, current->data);
        current = current->next;
    }
}

// Function to access the character at a given index in the string
char charAt(const MyString& str, int index) {
    int i = 0;
    Node* current = str.head;
    
    while (current != nullptr && i < index) {
        current = current->next;
        i++;
    }
    // list is empty, return '\0'
    if (current == nullptr) {
        return '\0';
    }
    // Otherwise, return the data at the current node
    return current->data;
}

// Function to display the string
void display(const MyString& str) {
    Node* current = str.head;
    while (current != nullptr) {
        std::cout << current->data;
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to remove a section of characters from the string based on position and length
void removeChars(MyString& str, int position, int length) {
    if (position < 0 || length <= 0) {
        return; // Invalid position or length, no action needed
    }

    Node* current = str.head;
    Node* prev = nullptr;
    int index = 0;

    while (current != nullptr && index < position) {
        prev = current;
        current = current->next;
        index++;
    }


    if (current == nullptr) {
        return;
    }

    // Remove the specified number of characters
    for (int i = 0; i < length; ++i) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    // Update the links in the list
    if (prev == nullptr) {
        // If removing from the beginning, update
        str.head = current;
    } else {
        prev->next = current;
    }
}

int main() {
    // Initialize an empty string
    MyString str = {nullptr};

    // Characters to the string
    append(str, 'a');
    append(str, 'b');
    append(str, 'c');
    append(str, 'd');
    append(str, 'e');
    append(str, 'f');
    append(str, 'g');

    std::cout << "Before removal: ";
    display(str); // Output: Before removal: abcdefg

    removeChars(str, 3, 2); // Remove 2 characters starting from position 3

    std::cout << "After removal: ";
    display(str); // Output: After removal: abcfg

    return 0;
}