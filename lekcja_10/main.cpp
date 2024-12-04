#include <cassert>
#include "RandomBinaryTree.h"

int main() {
    RandomBinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);


    assert(tree.calc_leaves_recursive() == 2);
    assert(tree.calc_leaves_iterative() == 2);

    assert(tree.calc_total_iterative() == 40);
    assert(tree.calc_total_iterative() == 40);

    tree.show();

    return 0;
}
