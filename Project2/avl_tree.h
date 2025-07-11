#include <iostream>
#include <algorithm>

#ifndef AVL_TREE_H_
#define AVL_TREE_H_

struct AvlNode {
    std::string key; 
    std::string value; 
    AvlNode* left_;
    AvlNode* right_;
    int height_;

    AvlNode(const std::string& k, const std::string& v):
    key(k), value(v), left_(nullptr), right_(nullptr), height_(0) {}

    /*Default Constructor*/
    AvlNode();
};

class AvlTree{
private:
    AvlNode* root_;
    //AvlNode* insert(AvlNode* node, const std::string& key, const std::string& value);
    AvlNode* remove(AvlNode* node, const std::string& key, const std::string& value);
    void printInOrder(AvlNode* node) const;
    void destroyTree(AvlNode* node);
    void makeEmpty(AvlNode * & node );
    void printTree(AvlNode *node, std::ostream & out ) const;
    AvlNode* findMin (AvlNode* node);
    AvlNode* findMax (AvlNode* node);
    int height(AvlNode* node);
    int getBalanceFactor(AvlNode* node);

    // rotations 
    AvlNode*  LL_rotation(AvlNode*& A);
    AvlNode*  RR_rotation(AvlNode*& A);
    AvlNode*  LR_rotation(AvlNode*& A);
    AvlNode*  RL_rotation(AvlNode*& A);

public:
    AvlTree();
    ~AvlTree();
    AvlNode* insert(AvlNode* node, const std::string& key, const std::string& value);
    void insert(const std::string& key, const std::string& value);
    std::string* search(const std::string& key);
    void remove(const std::string& key);
    void printInOrder() const;
    bool isEmpty() const;
    void clear();
};

#endif