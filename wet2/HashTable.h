#ifndef HASH_TABLE
#define HASH_TABLE

#include "Array.h"
#include "linkedList.h"


template<class T>
class HashTable {
public:

    double MAX_LOAD_FACTOR = 0.75;
    int m_size;
    Array<List<T>*>* m_arr;
    int m_assignedCounter;

    int hashFunc(int id) {
        return id%m_size;
    }

    void deleteArr(Array<List<T>*>* arr) {
        for(int i=0; i < arr->getSize(); i++) {
            List<T>* temp = arr->get(i);
            if(temp) {
                delete temp;
            }
        }
    }
    
    void resizeArray() {
        m_size = m_size*2;
        Array<List<T>*>* newArray = new Array<List<T>*>(m_size,nullptr);
        Array<List<T>*>* oldArray = m_arr;
        m_arr = newArray;
        int oldCounter = m_assignedCounter;
        m_assignedCounter = 0;
        try {
            for(int i=0; i<m_size/2; i++) {
                List<T>* tempData = oldArray->get(i);
                if(tempData) {
                    Node<T>* tempNode = tempData->ptrToHead();
                    while(tempNode) {
                        insert(tempNode->getID(), tempNode->getData());
                        tempNode = tempNode->getNext();
                    }
                }
            }
        }
        catch(...) {
            m_arr = oldArray;
            m_size = m_size/2;
            m_assignedCounter = oldCounter;
            deleteArr(newArray);
            delete newArray;
            throw;
        }
        deleteArr(oldArray);
        delete oldArray;
    }

//public:

    HashTable() : MAX_LOAD_FACTOR(0.75), m_size(8), m_arr(new Array<List<T>*>(m_size, nullptr)), m_assignedCounter(0) {}

    ~HashTable() {
        deleteArr(m_arr);
        delete m_arr;
    }

    bool insert(int id, T data) {
        if(((double)(m_assignedCounter)/m_size) >= MAX_LOAD_FACTOR) {
            resizeArray();
        }
        int index = hashFunc(id);
        if(m_arr->isAssigned(index)) {
            List<T>* tempList = m_arr->get(index);
            if(!tempList->findId(id)) {
                tempList->insert(data, id);
                m_assignedCounter++;
                return true;
            }
            return false;
        }
        List<T>* tempList = new List<T>();
        tempList->insert(data, id);
        m_arr->store(index, tempList);
        m_assignedCounter++;
        return true;
    }

    Node<T>* find(int id) {
        int index = hashFunc(id);
        List<T>* list = m_arr->get(index);
        if(list) {
            return list->findId(id);
        }
        return nullptr;
    }

};

#endif // HASH_TABLE