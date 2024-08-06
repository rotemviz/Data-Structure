#include <iostream>
#include "HashTable.h"


int main() {
    
    HashTable<int*> hash;

    int y = 12;
    //int z = 0;

    hash.insert(17429, &y);
    hash.insert(29484755, &y);
    hash.insert(437834, &y);
    std::cout << hash.m_assignedCounter << std::endl;
    std::cout << hash.m_size << std::endl;
    hash.insert(3838484, &y);
    std::cout << hash.m_assignedCounter << std::endl;
    std::cout << hash.m_size << std::endl;
    //hash.insert(4994, &y);
    //hash.insert(497, &y);
    //std::cout << hash.m_assignedCounter << std::endl;
    //std::cout << hash.m_size << std::endl;
    //hash.insert(49941, &y);
    //std::cout << hash.m_assignedCounter << std::endl;
    //std::cout << hash.m_size << std::endl;
    //hash.insert(49942, &y);
    //hash.insert(494, &y);
    //std::cout << hash.m_assignedCounter << std::endl;
    
    //Node<int*>* temp = hash.find(29484755);
    //int x = temp->getID();
    //std::cout << x << std::endl;
    
}