#include <iostream>

// Define the structure for a single node
struct Node {
    int digit;
    Node* next;
};

// Function to create a new node with the given digit
Node* createNode(int digit) {
    return new Node{digit, nullptr};
}

// Function to insert a new node with the given digit at the beginning of the list
void insertNode(Node*& head, int digit) {
    Node* newNode = createNode(digit);
    newNode->next = head;
    head = newNode;
}

// Function to convert an integer to a list of digits
Node* intToList(int value) {
    // Handle the case where the value is 0 separately
    if (value == 0) {
        return createNode(0);
    }

    Node* head = nullptr;

    while (value > 0) {
        int digit = value % 10; // Extract the least significant digit
        insertNode(head, digit); // Insert the digit as a new node at the beginning of the list
        value /= 10; // Remove the least significant digit
    }

    return head;
}

// Function to display the list of digits
void displayList(Node* head) {
    if (head == nullptr) {
        std::cout << "Empty list" << std::endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->digit << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Function to deallocate memory for the list
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test the intToList function
    int value = 149;
    Node* list = intToList(value);

    std::cout << "Linked list representation of " << value << ": ";
    displayList(list); // Output: Linked list representation of 149: 1 4 9

    deleteList(list);

    return 0;
}