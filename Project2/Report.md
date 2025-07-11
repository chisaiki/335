# Library Book Catalog System (Using Hash Table with AVL Tree Chaining)
The goal of this assignment is to help understand how to implement a hash table with separate chaining using AVL trees instead of linked lists. Implement the hash table in a real-world application involving a library book catalog system.
## Description of the AVL Tree.
### Explanation of Integration with the Hash Table.
The integration of the Avl Trees with the Hash table is similar to using a linked list. The buckets store the pointer to the root node of each Avl Tree. 

```cpp
/*Each bucket stores an AVL tree of key-value pairs*/
    std::vector<AvlTree> table;
    int numBuckets; 
```

The insert function, as defined below, references the hash table and the index generated to find which bucket to use, or in this case, which root node to begin the book insertion.

```cpp
 void insert(const std::string& key, const Books& book) 
    {
        int index = hashFunction(key);
        
        // Combine book info into a single string
        std::string bookInfo = book.author_ + ", " + book.genre_;
        table[index].insert(key, bookInfo);
    }
```

Insertion then follows the algorithm created for Avl Tree insertion, where it begins at the root node and follows the tree structure:

```cpp
void AvlTree::insert(const std::string& key, const std::string& value){
    root_ = insert(root_, key, value);
}
```

#### How AVL Insert Algorithm Works:

The AVL insertion process follows these key steps:

1. **Standard BST Insertion**: Insert the node like a regular binary search tree
2. **Update Heights**: Recalculate heights of affected nodes on the path back up
3. **Check Balance**: Calculate balance factors to detect imbalances
4. **Perform Rotations**: If imbalanced, perform appropriate rotations to restore AVL property

#### Step-by-Step Breakdown:

```cpp
AvlNode* AvlTree::insert(AvlNode* node, const std::string& key, const std::string& value) {
    // Step 1: Standard BST insertion
    if (node == nullptr) 
        return new AvlNode(key, value);  // Base case: create new leaf node
    
    else if (key < node->key) {
        node->left_ = insert(node->left_, key, value);   // Recurse left
        
        // Step 2: Check for left-heavy imbalance
        if (height(node->left_) - height(node->right_) == 2) {
            // Step 3: Determine rotation type
            if (key < node->left_->key)
                node = LL_rotation(node);    // Left-Left case
            else
                node = LR_rotation(node);    // Left-Right case
        }
    }
    else if (node->key < key) {    
        node->right_ = insert(node->right_, key, value);  // Recurse right
        
        // Step 2: Check for right-heavy imbalance  
        if (height(node->right_) - height(node->left_) == 2) {
            // Step 3: Determine rotation type
            if (node->right_->key > key)
                node = RR_rotation(node);    // Right-Right case
            else
                node = RL_rotation(node);    // Right-Left case
        }
    }
    else {
        // Key already exists - update value
        node->value = value;
    }
    
    // Step 4: Update height of current node
    node->height_ = std::max(height(node->left_), height(node->right_)) + 1;
    return node;
}
```

#### How AVL Search Algorithm Works:

The AVL search algorithm is simpler than insertion because it doesn't need to modify the tree structure or perform rotations. It follows the standard Binary Search Tree search pattern:

```cpp
std::string* AvlTree::search(const std::string& key) {
    AvlNode* current = root_;
    while (current != nullptr) {
        if (key < current->key)
            current = current->left_;       // Go left if key is smaller
        else if (key > current->key)
            current = current->right_;      // Go right if key is larger
        else
            return &current->value;         // Found! Return pointer to value
    }
    return nullptr;                         // Key not found
}
```

#### Step-by-Step Search Process:

1. **Start at Root**: Begin search at the root node of the AVL tree
2. **Compare Keys**: Compare the search key with current node's key
3. **Navigate Tree**: 
   - If `search_key < current_key` → go to left child
   - If `search_key > current_key` → go to right child  
   - If `search_key == current_key` → found! Return the value
4. **Repeat**: Continue until key is found or we reach a null pointer
5. **Return Result**: Return pointer to value if found, nullptr if not found

#### Search in Hash Table Context:

When searching in the hash table:
```cpp
std::string search(const std::string& key) {
    int index = hashFunction(key);              // O(1) - find bucket
    std::string* result = table[index].search(key);  // O(log m) - search AVL tree
    return result ? *result : "Key not found";
}
```
Where `m` is the number of keys in that specific bucket.


#### How AVL Delete Algorithm Works:

AVL deletion is the most difficult operation because it must handle three different node deletion cases while maintaining the AVL balance property. For the two-child case, the Avl Tree must find and replace node's data with successor's data, then recursively delete successor. Deletion can trigger cascading balance adjustments, the tree may need rotations at multiple levels causing a lot of backtracking. As evidenced in the code below:
```cpp
    /*BACKTRACKING*/
    // After deleting from left subtree
    if (height(node->right_) - height(node->left_) == 2) {
        // Rotation needed
    }
    // After deleting from right subtree  
    if (height(node->left_) - height(node->right_) == 2) {
        // Rotation needed
    }
```
#### Rebalancing After Deletion:

Unlike insertion (which needs at most 2 rotations), deletion may require rebalancing at **every level** on the path back to the root:

- After deleting from left subtree → check for right-heavy imbalance
- After deleting from right subtree → check for left-heavy imbalance
- Same rotation logic as insertion (LL, RR, LR, RL)

Included below is the AvlTree remove functions:

```cpp
void AvlTree::remove(const std::string& key) {
    root_ = remove(root_, key, " ");
}

AvlNode* AvlTree::remove(AvlNode* node, const std::string& key, const std::string& value) {
    if(node == nullptr) return nullptr;  // Key not found
    
    // Step 1: Standard BST deletion - find the node
    if(key < node->key) {
        node->left_ = remove(node->left_, key, value);
        // Check for right-heavy imbalance after left subtree deletion
        if (height(node->right_) - height(node->left_) == 2) {
            if (height(node->right_->right_) >= height(node->right_->left_))
                node = RR_rotation(node);
            else
                node = RL_rotation(node);
        }
    }
    else if(node->key < key) {
        node->right_ = remove(node->right_, key, value);
        // Check for left-heavy imbalance after right subtree deletion
        if (height(node->left_) - height(node->right_) == 2) {
            if(height((node->left_)->left_) >= height((node->left_)->right_))
                node = LL_rotation(node);
            else 
                node = LR_rotation(node);
        }
    }
    else { 
        // Step 2: Found the node to delete - handle three cases
        if((node->left_ != nullptr) && (node->right_ != nullptr)) { 
            // Case 3: Node with two children
            AvlNode* minNode = findMin(node->right_);  // Find inorder successor
            node->key = minNode->key;                  // Replace key
            node->value = minNode->value;              // Replace value
            node->right_ = remove(node->right_, minNode->key, minNode->value);
            
            // Check balance after successor removal
            if(height(node->left_) - height(node->right_) == 2) {
                if(height((node->left_)->left_) >= height((node->left_)->right_))
                    node = LL_rotation(node);
                else 
                    node = LR_rotation(node);
            }
        }
        else {
            // Case 1 & 2: Node with 0 or 1 child
            AvlNode* oldNode = node;
            node = (node->left_ != nullptr) ? node->left_ : node->right_;
            delete oldNode;
        }
    }
    
    // Step 3: Update height and return
    if(node != nullptr)
        node->height_ = std::max(height(node->left_), height(node->right_)) + 1;
    return node;
}
```

#### Delete in Hash Table Context:

```cpp
void remove(const std::string& key) {
    int index = hashFunction(key);       // O(1) - find bucket
    table[index].remove(key);           // O(log m) - delete from AVL tree
}
```
## Time and Space Complexity Analysis
### Time Complexity
The operations of the HashMap, particularly search, insert and delete using Avl Trees as the underlying data structure. HashMaps alone are $\theta$(1) when it comes to these operations. The worst case depends on which data structure is using for chaining, in this case it is Avl Trees. <br>
Due to the nature of the Avl Tree, the search, insert and deletion is all **O(logn)**. This due to the tree always maintaining a balanced height using rotations. The balance factor for each node makes sure the height difference is no greater than 1. 
- Search, Insert, Deletion all follow only one path from the root to the target; therefore, since the path length is equal to the tree height, the operations are all O(log n).

### Space Complexity
Overall the storing books into the tree is **O(n)** where n is the number of books being added to the data structure. The insert and delete operations use **O(log n)** auxiliary space due to their recursive implementations. The maximum recursion depth is the tree height which is O(log n); each recursive call adds one frame to the call stack. Search does not require creation of any new space so it has a constant time of **O(1)**.
