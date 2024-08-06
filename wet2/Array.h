#ifndef ARRAY
#define ARRAY
#include <iostream>

template<class T>
class Array {

    T m_constant;
    int m_size;
    int m_top;
    T* A;
    int* B;
    int* C;
    
public:
    Array(int size, T constant) : m_constant(constant), m_size(size), m_top(0), A(new T[m_size]), B(new int[m_size]), C(new int[m_size]) {};

    ~Array() {
        delete [] A;
        delete [] B;
        delete [] C;
    }

    int getSize() const {
        return m_size;
    }

    bool isAssigned(int i) const {
        //std::cout << i << std::endl;
        //std::cout << B[i] << std::endl;
        return (B[i] < m_top && B[i] >= 0 && C[B[i]] == i);
    }

    T get(int i) {
        return isAssigned(i) ? A[i] : m_constant;
    }

    void store(int i, const T& data) {
        if(!isAssigned(i)) {
            C[m_top] = i;
            B[i] = m_top;
            m_top++;
        }
        A[i] = data;
    }
};

#endif 