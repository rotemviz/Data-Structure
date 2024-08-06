#ifndef HASH_TABLE
#define HASH_TABLE

#include "linkedList.h"



template<class T>
class HashTable {
public:

    double MAX_LOAD_FACTOR;
    int m_size;
    List<T>* m_arr;
    int m_assignedCounter;

    int hashFunc(int id) {
        return id%m_size;
    }

    void resizeArray() {
        m_size = m_size*2;
        List<T>* newArray = new List<T>[m_size];
        List<T>* oldArray = m_arr;
        int oldCounter = m_assignedCounter;
        m_assignedCounter = 0;
        try {
            for(int i=0; i<m_size/2; i++) {
                List<T>& tempData = oldArray[i];
                Node<T>* tempNode = tempData.ptrToHead();
                while(tempNode){
                    std::cout << "checkResize" << std::endl;
                    this->insert(tempNode->getID(), tempNode->getData());
                    std::cout << "check" << std::endl;
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

//public:

    HashTable() : MAX_LOAD_FACTOR(0.75), m_size(4), m_arr(new List<T>[m_size]), m_assignedCounter(0) {}

    ~HashTable() {
        delete [] m_arr;
    }

    bool insert(int id, T data) {
        if(((double)(m_assignedCounter)/m_size) >= MAX_LOAD_FACTOR) {
            std::cout << "check" << std::endl;
            resizeArray();
        }
        int index = hashFunc(id);
        //std::cout << "check22" << std::endl;
        List<T>& tempList = m_arr[index];
        (tempList.ptrToHead())->getID();
        std::cout << "check77777" << std::endl;
        if(!tempList.findId(id)) {
            std::cout << "check55" << std::endl;
            tempList.insert(data, id);
            //std::cout << "check1111" << std::endl;
            m_assignedCounter++;
            return true;
        }
        std::cout << "checkOut" << std::endl;
        return false;
    }

    Node<T>* find(int id) {
        int index = hashFunc(id);
        List<T>& list = m_arr[index];
        return list.findId(id);
        
    }

};

#endif // HASH_TABLE