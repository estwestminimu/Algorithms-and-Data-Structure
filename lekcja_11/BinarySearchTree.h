#include <iostream>
#include <cassert>
#include <climits>

template<typename T>
struct BSTNode {
    T value;
    BSTNode *left;
    BSTNode *right;

    BSTNode(const T &val) : value(val), left(nullptr), right(nullptr) {
    }

    ~BSTNode() {
        delete left;
        delete right;
    }
};

template<typename T>
class BinarySearchTree {
    BSTNode<T> *root;

public:
    BinarySearchTree() : root(nullptr) {
    }

    ~BinarySearchTree() { clear(); }

    T &top() {
        assert(root != nullptr);
        return root->value;
    } // podgląd korzenia
    void insert(const T &item) { root = insert(root, item); }

    T *search(const T &item) const {
        auto ptr = search(root, item);
        return ((!ptr) ? nullptr : &(ptr->value));
    }

    T *iter_search(const T &item) const {
        auto node = root;

        while (node) {
            if (item == node->value) {
                return &(node->value);
            }
            if (item < node->value) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        return nullptr;
    }

    void clear() {
        delete root;
        root = nullptr;
    }

    bool isBST() {
        return isBSTRecursive(root, INT_MIN, INT_MAX);
    }

    void setRoot(BSTNode<T> *newRoot) {
        clear();
        root = newRoot;
    }

    BSTNode<T> *getRoot() const {
        return root;
    }

    T *find_min() {
        BSTNode<T> *node = root;
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node ? &(node->value) : nullptr;
    }

    T *find_max() {
        BSTNode<T> *node = root;
        while (node != nullptr && node->right != nullptr) {
            node = node->right;
        }
        return node ? &(node->value) : nullptr;
    }

    void display() {
        display(root, 0);
    }

    //Z przykladu (Maksymilian Brzozowski)
    void display(BSTNode<T> *node, int level) {
        if (!node) return;
        display(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "   |";
        }
        std::cout << "---" << node->value << std::endl;
        display(node->left, level + 1);
    }

    private:
        BSTNode<T> *insert(BSTNode<T> *node, const T &item) {
        if (!node) return new BSTNode<T>(item);
        if (item < node->value) {
            node->left = insert(node->left, item);
        } else if (item > node->value) {
            node->right = insert(node->right, item);
        }
        return node;
    }

    BSTNode<T> *search(BSTNode<T> *node, const T &item) const {
        if (!node || node->value == item) return node;
        if (item < node->value) return search(node->left, item);
        return search(node->right, item);
    }

    bool isBSTRecursive(BSTNode<T> *node, T minVal, T maxVal) {
        if (!node) return true;
        if (node->value <= minVal || node->value >= maxVal) return false;

        return isBSTRecursive(node->left, minVal, node->value) &&
               isBSTRecursive(node->right, node->value, maxVal);
    }
};