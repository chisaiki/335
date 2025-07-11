#include <iostream>
#include <string>
#include "avl_tree.h"

int main()
{
    AvlTree tree;
    AvlNode* book = new AvlNode("key", "value");


    tree.insert(book->key, book->value);
    tree.insert("hello2", "sam1");
    tree.insert("The Great Gatsby", "sam2");

    std::cout << "Contains book: " << (tree.contains(book->key) ? "Yes" : "No") << std::endl;
    std::cout << "Contains hello1: " << (tree.contains("hello1") ? "Yes" : "No") << std::endl;
    std::cout << "Contains bye: " << (tree.contains("bye") ? "Yes" : "No") << std::endl;

    std::cout << "__________________________" << std::endl;
    tree.printInOrder();
    std::cout << "__________________________" << std::endl;
    std::cout << *(tree.search(book->key));

    // tree.inOrder(); // Uncomment if you have this method
    

    return 0;
}