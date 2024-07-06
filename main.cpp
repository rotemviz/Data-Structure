#include "AVL_Tree.h"

int main() {
    AVL_Tree<int,int> tree;
    tree.insert(12, 1);
    tree.insert(13, 4);
    tree.insert(7, 7);
    tree.insert(3, 3);
    tree.insert(14, 3);
    tree.insert(15, 3);
    tree.insert(16, 3);
    tree.insert(17, 3);
    tree.insert(18, 3);
    tree.print();
}
