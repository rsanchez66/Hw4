#include <iostream>

// Define the structure
struct Node {
    char data;
    Node* next;
};

// Define the structure for our string
struct MyString {
    Node* head; 
};

// Function to append a character
void append(MyString& str, char ch) {
    // Create a new node with the given character
    Node* newNode = new Node{ch, nullptr};

    // If the string is empty, set the new node
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

// Function to access the character
char charAt(const MyString& str, int index) {
    int i = 0;
    Node* current = str.head;

    while (current != nullptr && i < index) {
        current = current->next;
        i++;
    }
    // If the index is empty, return '\0'
    if (current == nullptr) {
        return '\0';
    }
    // Otherwise, return the data at the current node
    return current->data;
}

int main() {
    // Initialize an empty string
    MyString str = {nullptr};

    // Append characters to the string
    append(str, 'a');
    append(str, 'b');
    append(str, 'c');

    
    std::cout << "Character at index 0: " << charAt(str, 0) << std::endl; // Output: a
    std::cout << "Character at index 1: " << charAt(str, 1) << std::endl; // Output: b
    std::cout << "Character at index 2: " << charAt(str, 2) << std::endl; // Output: c
    std::cout << "Character at index 3: " << charAt(str, 3) << std::endl; // Output: (empty, '\0')

    return 0;
}