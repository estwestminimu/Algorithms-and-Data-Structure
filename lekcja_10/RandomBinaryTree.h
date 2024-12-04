#ifndef RANDOMBINARYTREE_H
#define RANDOMBINARYTREE_H



#include <stack>
#include <cstdlib>
#include <iostream>

template <typename T>
struct BSTNode {
    T value;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const T& val) : value(val), left(nullptr), right(nullptr) {} //konsturktor wezla - wskazuje na null
    ~BSTNode() {
        delete left;
        delete right;
    }
};

template <typename T>
class RandomBinaryTree {
    BSTNode<T>* root;

public:
    RandomBinaryTree() : root(nullptr) {}


    //Jesli wezly sa tworzone przez nwe to delete bedzie siegal do lewego i prawego dziecka wykonujac sie rekurencyjnie

    ~RandomBinaryTree() { delete root; } //usuwa cale drzewo

    //Usuwa wszystkie wezly ale drzewo nadaje sie do uzytku cos jak nowe plotno
    void clear() { delete root; root = nullptr; }

    //sprawdzamy tylko korzen
    bool empty() const { return root == nullptr; }

    void insert(const T& item) { root = insert(root, item); }




    //przy wyszukiwaniu warto byloby dostac czy ten elemen istnieje
    // NIE - zwracamy pointer na null
    // TAK - zwracamy wskaxnik do wartosci



    // Zliczanie lisci
    int calc_leaves_recursive();
    int calc_leaves_iterative();

    //sumowanie wartosci
    T calc_total_recursive();
    T calc_total_iterative();

    void display(BSTNode<T> *node, int level);

    //wyswietlanie calego drzewa od korzenia
    void show();

private:
    BSTNode<T>* insert(BSTNode<T>* node, const T& item);//wstawianie wezla

    //funkcje pomocznicze
    void count_leaves_recursive(BSTNode<T>* node, int& leaf_count);
    void sum_nodes_recursive(BSTNode<T>* node, T& nodesum);
};

template <typename T>
void RandomBinaryTree<T>::sum_nodes_recursive(BSTNode<T>* node, T& nodesum) {
    if (node == nullptr) return; //koniec galezi
    nodesum += node->value;
    //przegladanie lewego i prawego dziecka
    sum_nodes_recursive(node->left, nodesum);
    sum_nodes_recursive(node->right, nodesum);
}


// Implementacja wstawiania do drzewa
template <typename T>
BSTNode<T> * RandomBinaryTree<T>::insert(BSTNode<T> *node, const T& item) {
    if (node == nullptr) {
        return new BSTNode<T>(item);
    }
    if (std::rand() % 2) {
        node->left = insert(node->left, item);
    } else {
        node->right = insert(node->right, item);
    }
    return node; // zwraca nowy korzeń
}

// Rekurencyjna wersja calc_leaves()
template <typename T>
void RandomBinaryTree<T>::count_leaves_recursive(BSTNode<T>* node, int& leaf_count) {
    if (node == nullptr) return; // Koniec galezi
    if (node->left == nullptr && node->right == nullptr) { //wskazuje na null z obu dzieci wiec jest to lisc
        leaf_count++;
        return;
    }
    count_leaves_recursive(node->left, leaf_count);
    count_leaves_recursive(node->right, leaf_count);
}

template <typename T>
int RandomBinaryTree<T>::calc_leaves_recursive() {
    int leaf_count = 0;
    count_leaves_recursive(root, leaf_count);
    return leaf_count;
}

template <typename T>
int RandomBinaryTree<T>::calc_leaves_iterative() {
    if (root == nullptr) return 0;

    int leaf_count = 0;
    std::stack<BSTNode<T>*> stack;
    stack.push(root); // Dodajemy korzeń na stos

    while (!stack.empty()) {
        BSTNode<T>* current = stack.top();
        stack.pop();

        // Wezel jest lisciem
        if (current->left == nullptr && current->right == nullptr) {
            leaf_count++;
        } else {
            // Dodajemy dzieci do stosu jesli istnieja
            if (current->right) stack.push(current->right);
            if (current->left) stack.push(current->left);
        }
    }

    return leaf_count;
}



//Calc

template <typename T>
T RandomBinaryTree<T>::calc_total_recursive() {
    T nodesum = 0;
    sum_nodes_recursive(root, nodesum);
    return nodesum;
}

// Iteracyjna wersja calc_total()
template <typename T>
T RandomBinaryTree<T>::calc_total_iterative() {
    if (root == nullptr) return 0;
    T nodesum = 0;
    std::stack<BSTNode<T>*> stack;
    stack.push(root); // Dodaj korzeń na stos

    while (!stack.empty()) {
        BSTNode<T>* current = stack.top();
        stack.pop();

        nodesum += current->value; // dodaje wartosc wezla

        // Dodaj dzieci na stos
        if (current->right) stack.push(current->right);
        if (current->left) stack.push(current->left);
    }

    return nodesum;
}



// Druga wersja display() z rysowaniem krawędzi drzewa (Maksymilian Brzozowski).
template <typename T>
void RandomBinaryTree<T>::display(BSTNode<T> *node, int level) {
    if (node == nullptr) return;
    display(node->right, level + 1);
    for (int i = 0; i < level; i++) {
        std::cout << "   |";
    }
    std::cout << "---" << node->value << std::endl;
    display(node->left, level + 1);
}


//wyswietlanie calego drzewa
template <typename T>
void RandomBinaryTree<T>::show() {
    display(root, 0);
}


#endif //RANDOMBINARYTREE_H
