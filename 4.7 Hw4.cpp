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

// ppend a character to the end of the string
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
        // New node to the end of the list
        current->next = newNode;
    }
}

// Two strings represented as linked lists
void concatenate(MyString& s1, const MyString& s2) {
    // If s2 is empty, return
    if (s2.head == nullptr) {
        return;
    }

    // Copy each nod of s2 and apprend it to s1
    Node* current = s2.head;
    while (current != nullptr) {
        append(s1, current->data);
        current = current->next;
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
    // The list is empty, return '\0'
    if (current == nullptr) {
        return '\0';
    }
    // Otherwise, return the data at the curren node
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

int main() {
    // Initialize two empty strings
    MyString s1 = {nullptr};
    MyString s2 = {nullptr};

    // Append characters to s1 and s2
    append(s1, 'a');
    append(s1, 'b');
    append(s2, 'c');
    append(s2, 'd');

    std::cout << "s1: ";
    display(s1); // Output: s1: ab
    std::cout << "s2: ";
    display(s2); // Output: s2: cd

    // s2 to s1
    concatenate(s1, s2);
    std::cout << "After concatenation: ";
    display(s1); // Output: abcd

    return 0;
}