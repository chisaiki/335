#include "avl_tree.h"
#include <iostream>
#include <list>
#include <vector>
#include <utility> // For std::pair
#include <string>
#include <map>
#include <functional> // For std::hash

class HashTable 
{
private:
    /*Each bucket stores an AVL tree of key-value pairs*/
    std::vector<AvlTree> table;
    int numBuckets; // Number of buckets

    // Hash function: computes an index for a given key
    int hashFunction(const std::string& key) const 
    {
        // Simple hash function for strings
        std::hash<std::string> hasher;
        return hasher(key) % numBuckets;
    }

public:
    // Constructor: initialize the table with a fixed number of buckets
    HashTable(int buckets) : numBuckets(buckets), table(buckets) {}

    // Insert a key-value pair
    void insert(const std::string& key, const std::string &value) 
    {
        int index = hashFunction(key);
        
        // Insert key-value pair into AVL tree
        table[index].insert(key, value);
    }

    // Remove a key-value pair by key
    void remove(const std::string& key) 
    {
        int index = hashFunction(key);
        
        // Remove from AVL tree
        table[index].remove(key);
    }

    // Search for a value by key
    std::string search(const std::string& key) 
    {
        int index = hashFunction(key);
        
        // Search in the AVL tree
        std::string* result = table[index].search(key);
        if (result != nullptr) {
            return *result;
        }
        
        return "Key not found";
    }

    // Display the hash table
    void display() const {
        for (int i = 0; i < numBuckets; ++i) {
            std::cout << "Bucket " << i << ": ";
            
            // For now, just indicate if the bucket has content
            // You would need to add a method to AvlTree to traverse and display all pairs
            std::cout << "[AVL Tree - use tree traversal to see contents]";
            std::cout << "\n";
        }
    }
};

int main() {
    HashTable hashTable(5); // Create a hash table with 5 buckets

    // Insert string key-value pairs
    hashTable.insert("apple", "fruit");
    hashTable.insert("carrot", "vegetable");
    hashTable.insert("banana", "fruit");

    // Search
    std::cout << hashTable.search("apple") << std::endl;  // "fruit"
    std::cout << hashTable.search("carrot") << std::endl;  // "fruit"


    // Remove
    hashTable.remove("carrot");

    return 0;
}
