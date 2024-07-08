#ifndef EX1_LinkedList_H
#define EX1_LinkedList_H

#include <iostream>

template<class T>
class List;

template<class V>
class Node {

    friend class List<V>;
    V m_data;
    Node* m_next;
    Node* m_prev;

    Node(const V& givenData) : m_data(givenData), m_next(nullptr), m_prev(nullptr) {}

public:
    V getData()const{
        return m_data;
    }
};

template<class T>
class List {

    Node<T>* m_head;
    Node<T>* m_tail;

public:

    List() : m_head(nullptr), m_tail(nullptr) {}

    ~List() {
        while (m_head != nullptr) {
            Node<T>* temp = m_head;
            m_head = m_head->m_next;
            delete temp;
        }
    }

    void insert(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if(m_tail == nullptr) {
            m_head = newNode;
            m_tail = newNode;
            return;
        }
        m_tail->m_next = newNode;
        newNode->m_prev = m_tail;
        m_tail = m_tail->m_next;
    }

    void remove(Node<T>* node) {
        if(node == nullptr || m_head == nullptr) {
            return;
        }
        Node<T>* temp = node;
        if(node == m_head) {
            m_head = m_head->m_next;
            delete temp;
            if(m_head == nullptr) {
                m_tail = nullptr;
                return;
            }
            m_head->m_prev = nullptr;
            if(m_head == m_tail) {
                m_tail->m_prev = nullptr;
            }
            return;
        }
        if(node == m_tail) {
            m_tail = m_tail->m_prev;
            delete temp;
            m_tail->m_next = nullptr;
            return;
        }
        (node->m_prev)->m_next = node->m_next;
        (node->m_next)->m_prev = node->m_prev;
        delete temp;
    }

    Node<T>* ptrToTail(){
        return m_tail;
    }

    Node<T>* ptrToHead(){
        return m_head;
    }


    void print1() {
        Node<T>* node = m_head;
        while (node != nullptr) {
            std::cout << node->m_data << "  ";
            node = node->m_next;
        }
        std::cout << std::endl;
    }
/*
    void print2() {
        Node* node = m_tail;
        while (node != nullptr) {
            std::cout << node->m_data << "  ";
            node = node->m_prev;
        }
        std::cout << std::endl;
    }

*/
};

#endif //List