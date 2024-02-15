#include <iostream>

// Define the structure for a single node in the list
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

// Function to add two digit lists and return the sum as a new list
Node* addLists(Node* list1, Node* list2) {
    Node* sumHead = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (list1 != nullptr || list2 != nullptr || carry > 0) {
        // Calculate the sum of digits and carry
        int digitSum = carry;
        if (list1 != nullptr) {
            digitSum += list1->digit;
            list1 = list1->next;
        }
        if (list2 != nullptr) {
            digitSum += list2->digit;
            list2 = list2->next;
        }

        // Update the carry
        carry = digitSum / 10;
        digitSum %= 10;

        // Insert the new digit into the sum list
        if (sumHead == nullptr) {
            sumHead = createNode(digitSum);
            current = sumHead;
        } else {
            current->next = createNode(digitSum);
            current = current->next;
        }
    }

    return sumHead;
}

int main() {
    // Test the addLists function
    int value1 = 149;
    int value2 = 222;

    Node* list1 = intToList(value1);
    Node* list2 = intToList(value2);

    std::cout << "First list: ";
    displayList(list1); // Output: First list: 1 4 9
    std::cout << "Second list: ";
    displayList(list2); // Output: Second list: 2 2 2

    Node* sumList = addLists(list1, list2);
    std::cout << "Sum list: ";
    displayList(sumList); // Output: Sum list: 3 6 1

    deleteList(list1);
    deleteList(list2);
    deleteList(sumList);

    return 0;
}