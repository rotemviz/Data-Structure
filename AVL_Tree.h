#ifndef EX1_AVL_Tree
#define EX1_AVL_Tree

#include <cmath>

template<class K, class V>
class AVL_Tree {

    class Node {

        friend class AVL_Tree;
        K m_key;
        V m_data;
        Node* m_right;
        Node* m_left;
        Node* m_parent;
        int m_height;

        Node(const V& givenData, const K& key) : 
            m_key(key), m_data(givenData), m_right(nullptr), m_left(nullptr), m_parent(nullptr), m_height(0) {}
    };

    void deleteTree(Node* givenRoot) {
        if(givenRoot == nullptr) {
            return;
        }
        deleteTree(givenRoot->m_left);
        deleteTree(givenRoot->m_right);
        delete givenRoot;
    }

    Node* m_root;

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

    bool insert(const K& key, const V& value, Node* root) {
        if(root == nullptr) {
            Node* newNode = new Node(key, value);
            m_root = newNode;
            return true;
        }
        bool success;
        if(root->m_key == key) {
            return false;
        }
        if(key < root->m_key) {
            if(root->m_left == nullptr) {
                Node* newNode = new Node(key, value);
                root->m_left = newNode;
                if(root->m_right == nullptr) {
                    root->m_height++;
                }
                return true;
            }
            success = insert(key, value, root->m_left);
        }
        if(key > root->m_key) {
            if(root->m_right == nullptr) {
                Node* newNode = new Node(key, value);
                root->m_right = newNode;
                if(root->m_left == nullptr) {
                    root->m_height++;
                }
                return true;
            }
            success = insert(key, value, root->m_right);
        }
        if(root->m_left != nullptr && root->m_right != nullptr) {

        }
    }
};


#endif