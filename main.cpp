#include "AVL_Tree.h"

int main() {
    AVL_Tree<int,int> tree;
    tree.insert(12,1);
    tree.insert(15,1);
    tree.insert(13,1);
    tree.insert(17,1);
    tree.insert(20,1);
    tree.insert(2,1);
    tree.insert(4,1);
    tree.insert(11,1);
    
    // tree.print();

    tree.remove(12);
    // std::cout << std::endl;
    // tree.print();

    // std::cout << std::endl;
    // std::cout << std::endl;

    AVL_Tree<int,int> copyToTree(tree);
    // copyToTree.print();
    // std::cout << std::endl;
    // tree.print();
}
