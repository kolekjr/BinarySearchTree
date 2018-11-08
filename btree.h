#ifndef BTREE_H
#define BTREE_H

#include <iostream>

namespace tree
{

template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree() {};
    BinarySearchTree(const BinarySearchTree& rhs);
    BinarySearchTree(BinarySearchTree&& rhs);
    ~BinarySearchTree();

    const Comparable& findMin() const;
    const Comparable& findMax() const;
    bool contains(const Comparable& x) const;
    bool isEmpty() const;
    void printTree() const;

    void makeEmpty();
    void insert(const Comparable& x);
    void insert(Comparable&& x);
    void remove(const Comparable& x);

    BinarySearchTree& operator=(const Comparable& rhs);
    BinarySearchTree& operator=(Comparable&& rhs);

private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const Comparable& el, BinaryNode* lt, BinaryNode* rt)
            : element{el}, left{lt}, right{rt} {}

        BinaryNode(Comparable&& el, BinaryNode* lt, BinaryNode* rt)
            : element{std::move(el)}, left{lt}, right{rt} {}
    };

    BinaryNode* root{nullptr};

    void insert(const Comparable& x, BinaryNode*& t);
    void insert(Comparable&& x, BinaryNode*& t);
    void remove(const Comparable& x, BinaryNode*& t);
    BinaryNode* findMax(BinaryNode* t) const;
    BinaryNode* findMin(BinaryNode* t) const;
    bool contains(const Comparable& x, BinaryNode* t) const;
    void makeEmpty(BinaryNode*& t);
    void printTree(BinaryNode* t) const;
    BinaryNode* clone(BinaryNode* t) const;
};

template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x) const
{
    return contains(x, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x)
{
    insert(x, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable&& x)
{
    insert(x, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x)
{
    remove(x, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty()
{
    makeEmpty(root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTree() const
{
    printTree(root);
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x, BinaryNode* t) const
{
    if (t == nullptr)
    {
        return false;
    }
    if (x < t->element)
    {
        return contains(x, t->left);
    }
    else if(x > t->element)
    {
        return contains(x, t->right);
    }
    else
    {
        return true;
    }
}

template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMin(BinaryNode* t) const
{
    if (t == nullptr)
    {
        return nullptr;
    }
    if (t->left == nullptr)
    {
        return t;
    }
    return findMin(t->left);
}

template<typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::findMax(BinaryNode* t) const
{
    if (t == nullptr)
    {
        return nullptr;
    }
    if (t->rightt == nullptr)
    {
        return t;
    }
    return findMin(t->right);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x, BinaryNode*& t)
{
    if (t == nullptr)
    {
        t = new BinaryNode{x, nullptr, nullptr};
    }
    if (x < t->element)
    {
        insert(x, t->left);
    }
    else if (x > t->element)
    {
       insert(x, t->right); 
    }
    else
        ;
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable&& x, BinaryNode*& t)
{
    if (t == nullptr)
    {
        t = new BinaryNode{std::move(x), nullptr, nullptr};
    }
    if (x < t->element)
    {
        insert(std::move(x), t->left);
    }
    else if (x > t->element)
    {
       insert(std::move(x), t->right); 
    }
    else
        ;
}

template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x, BinaryNode*& t)
{
    if (t == nullptr)
    {
        return;
    }

    if (x < t->element)
    {
        remove(x, t->left);
    }
    else if (x > t->element)
    {
        remove(x, t->right);
    }
    else if (t->left != nullptr && t->right != nullptr)
    {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else
    {
        BinaryNode* oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}

template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode*& t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
    makeEmpty();
}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode* t) const
{
    if (t != nullptr)
    {
        printTree(t->left);
        printTree(t->right);
        std::cout << t->element << "\n";
    }
}

};

#endif