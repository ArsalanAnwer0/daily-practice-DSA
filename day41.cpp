// // Hash Maps using STL unordered map
// #include<iostream>
// #include<unordered_map>
// using namespace std;

// int main(){

//     unordered_map<string, int> phoneBook;
//     phoneBook["Arsalan"] = 99666;
//     phoneBook["Arham"] = 111222;

//     cout << "Arsalan number: " << phoneBook["Arsalan"];

//     phoneBook.erase("Arsalan");
    
    

//     return 0;
// }
// #include <iostream>
// #include <vector>
// #include <list>
// #include <utility> // for std::pair
// #include <string>

// using namespace std;

// class HashMap {
// private:
//     static const int hashSize = 10; // Size of the hash table
//     vector<list<pair<string, int>>> table; // Array of lists to handle collisions

//     int hashFunction(const string& key) {
//         // Simple hash function: sum of ASCII values of characters
//         int hash = 0;
//         for (char ch : key) {
//             hash += ch;
//         }
//         return hash % hashSize; // Return index within the table size
//     }

// public:
//     HashMap() {
//         table.resize(hashSize); // Initialize the hash table
//     }

//     void insert(const string& key, int value) {
//         int index = hashFunction(key);
//         // Check if the key already exists and update it
//         for (auto& pair : table[index]) {
//             if (pair.first == key) {
//                 pair.second = value; // Update value
//                 return;
//             }
//         }
//         // If key does not exist, add a new key-value pair
//         table[index].emplace_back(key, value);
//     }

//     int search(const string& key) {
//         int index = hashFunction(key);
//         for (const auto& pair : table[index]) {
//             if (pair.first == key) {
//                 return pair.second; // Return the value
//             }
//         }
//         return -1; // Return -1 if key not found
//     }

//     void remove(const string& key) {
//         int index = hashFunction(key);
//         auto& cell = table[index];
//         for (auto it = cell.begin(); it != cell.end(); ++it) {
//             if (it->first == key) {
//                 cell.erase(it); // Remove the key-value pair
//                 return;
//             }
//         }
//     }
// };

// int main() {
//     HashMap myMap;

//     // Insert key-value pairs
//     myMap.insert("Arsalan", 99666);
//     myMap.insert("Arham", 111222);

//     // Search for a value
//     cout << "Arsalan's number: " << myMap.search("Arsalan") << endl;

//     // Delete a key-value pair
//     myMap.remove("Arsalan");
//     cout << "Arsalan's number after deletion: " << myMap.search("Arsalan") << endl;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair
#include <string>

using namespace std;

// Define the HashMap class
class HashMap {
private:
    static const int hashSize = 10; // Size of the hash table
    // Vector of lists to handle collisions (each index can have multiple key-value pairs)
    vector<list<pair<string, int>>> table; 

    // Hash function to calculate the index for a given key
    int hashFunction(const string& key) {
        int hash = 0; // Initialize hash value
        // Calculate the hash value by summing ASCII values of characters in the key
        for (char ch : key) {
            hash += ch;
        }
        // Return the index within the table size
        return hash % hashSize; 
    }

public:
    // Constructor to initialize the hash table
    HashMap() {
        table.resize(hashSize); // Resize the table to the defined hash size
    }

    // Method to insert a key-value pair into the hash map
    void insert(const string& key, int value) {
        int index = hashFunction(key); // Get the index for the key
        // Check if the key already exists in the list at that index
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update the value if the key exists
                return; // Exit the method
            }
        }
        // If the key does not exist, add a new key-value pair to the list
        table[index].emplace_back(key, value);
    }

    // Method to search for a value by its key
    int search(const string& key) {
        int index = hashFunction(key); // Get the index for the key
        // Look through the list at that index
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second; // Return the value if the key is found
            }
        }
        return -1; // Return -1 if the key is not found
    }

    // Method to remove a key-value pair from the hash map
    void remove(const string& key) {
        int index = hashFunction(key); // Get the index for the key
        auto& cell = table[index]; // Reference to the list at that index
        // Iterate through the list to find the key
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->first == key) {
                cell.erase(it); // Remove the key-value pair if found
                return; // Exit the method
            }
        }
    }
};

int main() {
    HashMap myMap; // Create an instance of HashMap

    // Insert key-value pairs into the hash map
    myMap.insert("Arsalan", 99666);
    myMap.insert("Arham", 111222);

    // Search for a value by key and print it
    cout << "Arsalan's number: " << myMap.search("Arsalan") << endl;

    // Delete a key-value pair from the hash map
    myMap.remove("Arsalan");
    // Try to search for the deleted key and print the result
    cout << "Arsalan's number after deletion: " << myMap.search("Arsalan") << endl;

    return 0; // End of the program
}