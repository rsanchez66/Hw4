#include <iostream>
#include <vector> // for std::vector

// Define the structure for student record
struct StudentRecord {
    int studentNumber;

};

// Define the student collection
struct StudentCollection {
    std::vector<StudentRecord> records;
};

// Function to remove a record with a specific student number
void removeRecord(StudentCollection* collection, int studentNumber) {
    for (auto it = collection->records.begin(); it != collection->records.end(); ++it) {
        if (it->studentNumber == studentNumber) {
            collection->records.erase(it);
            return; // record found and removed, exit the function
        }
    }
    std::cout << "Record with student number " << studentNumber << " not found." << std::endl;
}

int main() {

    StudentCollection collection;
    
    // Populate the collection with some records
    collection.records.push_back({123});
    collection.records.push_back({456});
    collection.records.push_back({789});

    std::cout << "Initial collection:" << std::endl;
    for (const auto& record : collection.records) {
        std::cout << "Student number: " << record.studentNumber << std::endl;
    }

    // Remove a record with student number 456
    removeRecord(&collection, 456);

    std::cout << "\nCollection after removing record:" << std::endl;
    for (const auto& record : collection.records) {
        std::cout << "Student number: " << record.studentNumber << std::endl;
    }

    return 0;
}