#ifndef ARRAY
#define ARRAY
#include <iostream>

template<class T>
class Array {

    int m_size;
    T* A;
    
public:
    Array(int size) :m_size(size), A(new T[m_size]){};

    ~Array() {
        delete [] A;
    }

    int getSize() const {
        return m_size;
    }

    const T& get(int i)const {
        return A[i];
    }

    void store(int i,  T& data) {
        A[i] = data;
    }
};

#endif 