#include "BinarySearchTree.h"

int main() {

    std::cout << "Drzewo z przykladu:" << std::endl;
    BinarySearchTree<int> tree1;
    BSTNode<int> *root1 = new BSTNode<int>(5);
    root1->left = new BSTNode<int>(3);
    root1->right = new BSTNode<int>(8);
    root1->left->left = new BSTNode<int>(1);
    root1->left->right = new BSTNode<int>(6);
    root1->right->left = new BSTNode<int>(7);
    root1->right->right = new BSTNode<int>(9);
    tree1.setRoot(root1);
    tree1.display();
    std::cout << "BST: " << (tree1.isBST() ? "Tak" : "Nie") << std::endl;


    std::cout << "\nPoprawne drzewo:" << std::endl;
    BinarySearchTree<int> tree2;
    tree2.insert(5);
    tree2.insert(3);
    tree2.insert(8);
    tree2.insert(1);
    tree2.insert(4);
    tree2.insert(7);
    tree2.insert(9);
    tree2.display();
    std::cout << "BST: " << (tree2.isBST() ? "Tak" : "Nie") << std::endl;

    return 0;
}
