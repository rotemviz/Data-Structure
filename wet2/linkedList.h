#ifndef EX1_LinkedList_H
#define EX1_LinkedList_H


template<class T>
class List;

template<class V>
class Node {

    friend class List<V>;
    V m_data;
    int m_id;
    Node* m_next;
    Node* m_prev;

    Node(const V& givenData, const int id) : m_data(givenData), m_id(id) ,m_next(nullptr), m_prev(nullptr) {}

public:

    V getData() const {
        return m_data;
    }

    int getID() const {
        return m_id;
    }

    Node<T>* getNext(const Node<T>* node) const {
        return node->m_next;
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

    void insert(const T& data, int id) {
        Node<T>* newNode = new Node<T>(data, id);
        if(m_tail == nullptr) {
            m_head = newNode;
            m_tail = newNode;
            return;
        }
        m_head->m_prev = newNode;
        newNode->m_next = m_head;
        m_head = newNode;
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

    Node<T>* ptrToTail()const{
        return m_tail;
    }

    Node<T>* ptrToHead()const{
        return m_head;
    }

    Node<T>* findId(int toFind) const {
        Node<T>* tempNode = m_head;
        while(tempNode != nullptr) {
            if(tempNode->id == toFind) {
                return tempNode;
            }
            tempNode = tempNode->m_next;
        }
        return nullptr;
    }

};

#endif //List