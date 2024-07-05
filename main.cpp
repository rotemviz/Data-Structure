#include "AVL_Tree.h"

int main() {
    AVL_Tree<int,int> tree;
    tree.insert(12, 1, tree.getRoot());
    tree.insert(13, 1, tree.getRoot());
    tree.insert(7, 1, tree.getRoot());
    tree.insert(3, 1, tree.getRoot());
    tree.print(tree.getRoot());
}
