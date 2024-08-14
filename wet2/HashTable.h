#ifndef HASH_TABLE
#define HASH_TABLE

#include "linkedList.h"



template<class T>
class HashTable {

    double MAX_LOAD_FACTOR;
    int m_size;
    List<T>* m_arr;
    int m_assignedCounter;

    int hashFunc(int id) {
        return id%m_size;
    }

    
    void deleteData(List<T>* arr){
        for(int i=0; i<m_size; i++) {
                List<T>& tempData = arr[i];
                Node<T>* tempNode = tempData.ptrToHead();
                while(tempNode){
                    delete (tempNode->getData());
                    tempNode = tempNode->getNext();
                }
        }
    }

    void resizeArray() {
        m_size = m_size*2;
        List<T>* newArray = new List<T>[m_size];
        List<T>* oldArray = m_arr;
        m_arr = newArray;
        int oldCounter = m_assignedCounter;
        m_assignedCounter = 0;
        try {
            for(int i=0; i<m_size/2; i++) {
                List<T>& tempData = oldArray[i];
                Node<T>* tempNode = tempData.ptrToHead();
                while(tempNode){
                    this->insert(tempNode->getID(), tempNode->getData());
                    tempNode = tempNode->getNext();
                }
            }
        }
        catch(...) {
            m_arr = oldArray;
            m_size = m_size/2;
            m_assignedCounter = oldCounter;
            delete [] newArray;
            throw;
        }
        delete [] oldArray;
    }

public:

    HashTable() : MAX_LOAD_FACTOR(0.75), m_size(1000), m_arr(new List<T>[m_size]), m_assignedCounter(0) {}

    ~HashTable() {
        deleteData(m_arr);
        delete [] m_arr;
    }

    bool insert(int id, T data) {
        if(((double)(m_assignedCounter)/m_size) >= MAX_LOAD_FACTOR) {
            resizeArray();
        }
        int index = hashFunc(id);
        List<T>& tempList = m_arr[index];
        if(!tempList.findId(id)) {
            tempList.insert(data, id);
            m_assignedCounter++;
            return true;
        }
        return false;
    }

    Node<T>* find(int id) {
        int index = hashFunc(id);
        List<T>& list = m_arr[index];
        return list.findId(id);
    }

};

#endif // HASH_TABLE

