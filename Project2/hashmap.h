#include "avl_tree.h"
#include <vector>
#include <string>
#include <map>
#include <functional> // For std::hash
#include <fstream>
#include <vector>

struct Books{
    /*Title (string) — used as the key.*/
    std::string title_;
    /*Author (string)*/
    std::string author_;
    /*Genre (string)*/
    std::string genre_;
};


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
    void insert(const std::string& key, const Books& book) 
    {
        int index = hashFunction(key);
        
        // Combine book info into a single string
        std::string bookInfo = book.author_ + ", " + book.genre_;
        table[index].insert(key, bookInfo);
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
        
        return "Book Not Found. May not exist in records.";
    }

    // Display the hash table
    void display() const {
        for (int i = 0; i < numBuckets; ++i) {
            std::cout << "Bucket " << i << ": ";
            if (table[i].isEmpty()) {
                std::cout << "[Empty]";
            } else {
                table[i].printInOrder();
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    void clear(){
        std::cout << "\nClearing Table Of Previous Storage\n" << std::endl;
        for (int i = 0; i < numBuckets; ++i) {
            table[i].clear();
        }
    }

    bool empty(){
        int emptyCounter = 0;
        for (int i = 0; i < numBuckets; ++i) {
            if (table[i].isEmpty()) {
                emptyCounter++;
            }
        }

        if(emptyCounter != numBuckets)
            return false;
        else
            return true;
    }
};
