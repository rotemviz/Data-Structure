#ifndef EX1_AVL_Tree
#define EX1_AVL_Tree

#include <cmath>
#include <exception>
#include <iostream>

template<class K, class V>
class AVL_Tree {

    class Node {

        friend class AVL_Tree;
        K m_key;
        V m_data;
        Node* m_right;
        Node* m_left;
        int m_height;

        Node(const K& key, const V& givenData) : 
            m_key(key), m_data(givenData), m_right(nullptr), m_left(nullptr), m_height(0) {}
    };

    Node* m_root;

    int maxHeight(int one, int two) const {
        if(one > two) {
            return one;
        }
        return two;
    }

    void deleteTree(Node* givenRoot) {
        if(givenRoot == nullptr) {
            return;
        }
        deleteTree(givenRoot->m_left);
        deleteTree(givenRoot->m_right);
        delete givenRoot;
    }

    void updateHeight(Node* root) {
        if(root->m_left != nullptr && root->m_right != nullptr) {
            root->m_height = 1 + maxHeight((root->m_left)->m_height, (root->m_right)->m_height);
        }
        else if(root->m_left != nullptr && root->m_right == nullptr) {
            root->m_height = 1 + (root->m_left)->m_height;
        }
        else if(root->m_left == nullptr && root->m_right != nullptr) {
            root->m_height = 1 + (root->m_right)->m_height;
        }
    }

    int getBalance(Node* root) const {
        int balance;
        if(root->m_left != nullptr && root->m_right != nullptr) {
            balance = (root->m_left)->m_height - (root->m_right)->m_height;
        }
        else if(root->m_left != nullptr && root->m_right == nullptr) {
            balance = (root->m_left)->m_height + 1;
        }
        else if(root->m_left == nullptr && root->m_right != nullptr) {
            balance = -1 - (root->m_right)->m_height;
        }
        return balance;
    }

    Node* rollRight(Node* root) {
        Node* newRoot = root->m_left;
        Node* rightNewRoot = newRoot->m_right;
        newRoot->m_right = root;
        root->m_left = rightNewRoot;
        updateHeight(root);
        updateHeight(newRoot);
        return newRoot;
    }

    Node* rollLeft(Node* root) {
        Node* newRoot = root->m_right;
        Node* leftNewRoot = newRoot->m_left;
        newRoot->m_left = root;
        root->m_right = leftNewRoot;
        updateHeight(root);
        updateHeight(newRoot);
        return newRoot;
    }

    Node* insert(const K& key, const V& value, Node* root) {
        if(root == nullptr) {
            return new Node(key, value);
        }
        if(root->m_key == key) {
            throw std::invalid_argument("The key already exist");
        }
        if(key < root->m_key) {
            root->m_left = insert(key, value, root->m_left);
        }
        if(key > root->m_key) {
            root->m_right = insert(key, value, root->m_right);
        }
        updateHeight(root);
        int balance = getBalance(root);
        if(balance == 2) {
            if(getBalance(root->m_left) >= 0) {
                return rollRight(root);
            }
            if(getBalance(root->m_left) < 0) {
                root->m_left = rollLeft(root->m_left);
                return rollRight(root);
            }
        }
        if(balance == -2) {
            if(getBalance(root->m_right) < 0) {
                return rollLeft(root);
            }
            if(getBalance(root->m_right) >= 0) {
                root->m_right = rollRight(root->m_right);
                return rollLeft(root);
            }
        }
        return root;
    }

    // change the name of the method
    Node* searchNum(Node* root, bool flag){
        if(root->m_left == nullptr){
            return root;
        }
        if(flag){
            return searchNum(root->m_right,false);
        }
        else{
            return searchNum(root->m_left,false);
        }
    }

    void print(Node* root) const {
        if(root == nullptr) {
            return;
        }
        print(root->m_left);
        std::cout << root->m_key << "   ";
        print(root->m_right);
    }
    //add 
    Node* remove(const K& key, Node* root){
        if(root == nullptr){
            throw std::invalid_argument("The key is not found");
        }
        if(key > root->m_key){
            root->m_right = remove(key,root->m_right);
        }
        else if(key < root->m_key){
            root->m_left = remove(key, root->m_left);
        }
        else{
            if(root->m_left == nullptr || root->m_right == nullptr){
                /*
                Node* nodeToDelete = root->m_right ? root->m_right : root->m_left;
                if(nodeToDelete == nullptr){
                    nodeToDelete = root;
                    root = nullptr;
                }
                else{
                    Node* temp = root;
                    root = nodeToDelete;
                    nodeToDelete = temp;
                    *root  = *nodeToDelete;
                }
                delete nodeToDelete;
                return root;
                */
               Node* nodeToDelete = root;
               if(root->m_left == nullptr){
                root = root->m_right;
               }
               else{
                root = root->m_left;
               }

               delete nodeToDelete;
            }
            else{
                Node* nextKeyInInorder = searchNum(root,true);
                //K = root->m_key;
                //V = root->m_data;
                root->m_key = nextKeyInInorder->m_key;
                root->m_data = nextKeyInInorder->m_data;
                root->m_right = remove(nextKeyInInorder->m_key, root->m_right);
                //check....
            }
        }

        if(root == nullptr){
            return root;
        }

        updateHeight(root);
        int balance = getBalance(root);
        if(balance == 2) {
            if(getBalance(root->m_left) >= 0) {
                return rollRight(root);
            }
            if(getBalance(root->m_left) < 0) {
                root->m_left = rollLeft(root->m_left);
                return rollRight(root);
            }
        }
        if(balance == -2) {
            if(getBalance(root->m_right) < 0) {
                return rollLeft(root);
            }
            if(getBalance(root->m_right) >= 0) {
                root->m_right = rollRight(root->m_right);
                return rollLeft(root);
            }
        }
        return root;
    }

public:

    AVL_Tree() : m_root(nullptr) {}

    ~AVL_Tree() {
        if(m_root == nullptr) {
            return;
        }
        deleteTree(m_root);
    }

    Node* find(const K& key, Node* root) {
        
    }

    void insert(const K& key, const V& value) {
        m_root = insert(key, value, m_root);
    }
    
    void remove(const K& key){
        remove(key, m_root);
    }

    void print() const {
        print(m_root);
    }

    bool isEmpty()const{
        return m_root == nullptr;
    }
};


#endif