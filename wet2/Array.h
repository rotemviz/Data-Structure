#ifndef ARRAY
#define ARRAY

template<class T>
class Array {

    T m_constant;
    int m_size;
    int m_top;
    T* A;
    T* B;
    T* C;
    
public:
    Array(int size, T constant) : m_constant(constant), m_size(size), m_top(0), A(new T(m_size)), B(new T(m_size)), C(new T(m_size)) {};

    ~Array() {
        delete A;
        delete B;
        delete C;
    }

    bool isAssigned(int i) const {
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