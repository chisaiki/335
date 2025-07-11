#include "AVL_tree.h"

AvlTree::AvlTree(): root_(nullptr) {}

AvlTree::~AvlTree() {
    destroyTree(root_);
}

void AvlTree::destroyTree(AvlNode* node) {
    if (node) {
        destroyTree(node->left_);
        destroyTree(node->right_);
        delete node;
    }
}

void AvlTree::insert(const std::string& key, const std::string& value){
    root_ = insert(root_, key, value);
}

AvlNode* AvlTree::insert(AvlNode* node, const std::string& key, const std::string& value) {
    if (node == nullptr) 
        return new AvlNode(key, value);
    
    else if (key < node->key) {
        node->left_ = insert(node->left_, key, value); 
            if (height(node->left_) - height(node->right_) == 2) {
                if (key < node->left_->key)
                    node = LL_rotation(node);
                else
                    node = LR_rotation(node);
            }
    }

    else if (node->key < key) {    
        node->right_ =insert(node->right_, key, value);
            if (height(node->right_) - height(node->left_) == 2) {
                if (node->right_->key > key)
                    RR_rotation(node);
                else
                    RL_rotation(node);
            }
    }

    else {
        node->value = value;
   }
    node->height_= std::max(height(node->left_), height(node->right_)) + 1;
    return node;
}

std::string* AvlTree::search(const std::string& key) {
    AvlNode* current = root_;
    while (current != nullptr) {
        if (key < current->key)
            current = current->left_;
        else if (key > current->key)
            current = current->right_;
        else
            return &current->value;
    }
    return nullptr;
}

void AvlTree::remove(const std::string& key) {
    root_ = remove(root_, key, " ");
}

AvlNode* AvlTree::remove(AvlNode* node, const std::string& key, const std::string& value){
    if(node==nullptr) return nullptr;
    
    if(key<node->key) {
        node->left_ = remove(node->left_, key, value);
        if (height(node->right_) - height(node->left_) == 2) {
    if (height(node->right_->right_) >= height(node->right_->left_))
        node = RR_rotation(node);
    else
        node = RL_rotation(node);
}
    }
    
    else if(node->key<key) {
        node->right_ = remove(node->right_, key, value);
        if (height(node->left_) - height(node->right_)==2) {
            if(height((node->left_)->left_) >= height ((node->left_)->right_))
                LL_rotation(node);
            else LR_rotation(node);
        }
    }

    else { 
        if((node->left_ != nullptr) && (node->right_ != nullptr)) { 
            AvlNode* minNode =  findMin(node->right_);
            node->key = minNode->key;
            node->value = minNode->value;
            node->right_ = remove(node->right_, minNode->key,minNode->value);
            if(height(node->left_)-height(node->right_)==2) {
                if(height((node->left_)->left_)>=height((node->left_)->right_))
                    LL_rotation(node);
                else LR_rotation(node);
            }
        }
        else {
            AvlNode* OldNode = node;
            node=(node->left_!=nullptr)?node->left_:node->right_;
            delete OldNode ;
        }
    }
    if(nullptr!=node)
        node->height_ = std::max(height(node->left_),height(node->right_))+1;
        return node;
}

void AvlTree::printInOrder() const{
    printInOrder(root_);
    std::cout << std::endl;
}

void AvlTree::printInOrder(AvlNode* node) const {
    if (!node) return;
    printInOrder(node->left_);
    std::cout << node->key << ": " << node->value << " || "; //std::endl;
    printInOrder(node->right_);
}

void AvlTree::makeEmpty(AvlNode * & node ){
       if( node != nullptr ){
            makeEmpty( node->left_ );
            makeEmpty( node->right_ );
            delete node;
        }
        node = nullptr;
}

AvlNode* AvlTree::findMin (AvlNode* node){
    if(!node) return nullptr;

    while(node->left_) node = node->left_;

    return node;
}

AvlNode* AvlTree::findMax (AvlNode* node){
    if(!node) return nullptr;

    while(node->left_) node = node->left_;

    return node;

}

int AvlTree::height(AvlNode* node){
    return node ? node->height_ : 0;
}

int AvlTree::getBalanceFactor(AvlNode* node){
    return height(node->left_) - height(node->right_);
}

AvlNode* AvlTree::LL_rotation(AvlNode*& A){
    AvlNode* B = A->left_;
    A->left_ = B->right_;
    B->right_ = A;

    A->height_ = std::max(height(A->left_), height(A->right_)) + 1;
    B->height_ = std::max(height(B->left_), height(B->right_)) + 1;

    return B;
}

AvlNode* AvlTree::RR_rotation(AvlNode*& A){
    AvlNode* B = A->right_;
    A->right_ = B->left_;
    B->left_ = A;

    A->height_ = std::max(height(A->left_), height(A->right_)) + 1;
    B->height_ = std::max(height(B->left_), height(B->right_)) + 1;

    return B;
}

AvlNode*  AvlTree::LR_rotation(AvlNode*& A){
    AvlNode* B = A->left_;
    AvlNode* C = B->right_;

    B->right_ = C->left_;
    A->left_ = C->right_;
    C->left_ = B;
    C->right_ = A;

    A->height_ = std::max(height(A->left_), height(A->right_)) + 1;
    B->height_ = std::max(height(B->left_), height(B->right_)) + 1;
    C->height_ = std::max(height(C->left_), height(C->right_)) + 1;

    return C;
}

AvlNode* AvlTree::RL_rotation(AvlNode*& A){
    AvlNode* B = A->right_;
    AvlNode* C = B->left_;

    B->left_ = C->right_;
    A->right_ = C->left_;
    C->left_ = A;
    C->right_ = B;

    A->height_ = std::max(height(A->left_), height(A->right_)) + 1;
    B->height_ = std::max(height(B->left_), height(B->right_)) + 1;
    C->height_ = std::max(height(C->left_), height(C->right_)) + 1;

    return C;
}

void AvlTree::clear() {
    makeEmpty(root_);
    root_ = nullptr;  /*Ensure root is set to nullptr after clearing*/
}

bool AvlTree::isEmpty() const {
    return root_ == nullptr;
}