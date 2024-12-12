#include <iostream>
#include <cassert>

template <typename T>
struct BSTNode {
    T value;
    BSTNode *left;
    BSTNode *right;

    BSTNode(const T& val) : value(val), left(nullptr), right(nullptr) {}
    ~BSTNode() { delete left; delete right; }
};

template <typename T>
class BinarySearchTree {
    BSTNode<T> *root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { clear(); }
    T& top() { assert(root != nullptr); return root->value; } // podgląd korzenia
    void insert(const T& item) { root = insert(root, item); }
    T* search(const T& item) const {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    T* iter_search(const T& item) const {
        for (auto node=root; node != nullptr; ) {
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
        return isBSTHelper(root, top(), top());
    }

    void setRoot(BSTNode<T>* newRoot) {
        clear();
        root = newRoot;
    }
    BSTNode<T>* getRoot() const {
        return root;
    }

    void display() {
        display(root, 0);
    }

    //Z przykladu (Maksymilian Brzozowski)
    void display(BSTNode<T>* node, int level) {
        if (!node) return;
        display(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            std::cout << "   |";
        }
        std::cout << "---" << node->value << std::endl;
        display(node->left, level + 1);
    }

private:
    BSTNode<T>* insert(BSTNode<T>* node, const T& item) {
        if (!node) return new BSTNode<T>(item);

        node->left = (item < node->value) ? insert(node->left, item) : node->left;
        node->right = (item >= node->value) ? insert(node->right, item) : node->right;

        return node;
    }

    bool isBSTHelper(BSTNode<T>* node, T minVal, T maxVal) {
        if (!node) return true;
        if (node->value >= maxVal || node->value <= minVal) return false;

        bool left = isBSTHelper(node->left, minVal, node->value);
        bool right = isBSTHelper(node->right, node->value, maxVal);

        return left && right;
    }
};
