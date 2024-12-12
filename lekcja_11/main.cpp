#include "BinarySearchTree.h"

int main() {

    //Drzewo z przykladu
    BinarySearchTree<int> tree;

    BSTNode<int>* root = new BSTNode<int>(5);

    root->left = new BSTNode<int>(3);
    root->left->left = new BSTNode<int>(1);
    root->left->right = new BSTNode<int>(6);

    root->right = new BSTNode<int>(8);
    root->right->left = new BSTNode<int>(7);
    root->right->right = new BSTNode<int>(9);

    tree.setRoot(root);

    tree.display(tree.getRoot(), 0);


    std::cout<<"BST: " << (tree.isBST() ? "Tak" : "Nie") << std::endl;
    return 0;
}