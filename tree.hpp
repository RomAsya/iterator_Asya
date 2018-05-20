#include "iterator.hpp"
#include <initializer_list>

namespace BSTree {

template <typename T>
class Tree {
public:

    Tree(std::initializer_list<T>);
    auto begin() -> pre_iterator<T>;
    auto end() -> pre_iterator<T>;

    auto rbegin() -> post_iterator<T>;
    auto rend() -> post_iterator<T>;
    auto push_back(const T&) -> void;
private:
    Node<T>* root;
};

template <typename T>
auto Tree<T>:: begin() -> pre_iterator <T> {
    pre_iterator<T> beg (root);
    return beg;
}

template <typename T>
auto Tree<T>:: rbegin() -> post_iterator <T> {
    Node<T> * curr = root;
    while((curr->left!=nullptr)||(curr->right!=nullptr)) {
        if (curr->left!=nullptr) { curr=curr->left; continue; }
        if (curr->right!= nullptr) {curr=curr->right;}
                }
 post_iterator<T> rbeg (curr);
    return rbeg;

}

template <typename T>
auto Tree<T>:: rend() -> post_iterator <T> {
    post_iterator<T> rend (root);
    return rend;
}


template <typename T>
auto Tree<T>:: end() -> pre_iterator <T> {
    Node<T> *curr=root;
    while ((curr->right!=nullptr || curr->left!=nullptr))
{ if (curr->right!=nullptr) curr=curr->right; else
{ if (curr->left!=nullptr) curr= curr->left; } }
    pre_iterator<T> end (curr);
    return end;
}



template <typename T>
auto Tree<T>:: push_back (const T& value) -> void {
    if (root == nullptr) {
        root = new Node<T> {value,nullptr,nullptr,nullptr};
        return ;
    }
    Node<T> * parent= root;
    Node<T> * curr= root;
    while ( curr != nullptr) {
        if (curr->data < value) curr= curr->right;
        else curr= curr->left;
        if (curr!=nullptr) parent= curr;
    }
    if (parent->data< value) parent->right = new Node <T> {value,
nullptr, nullptr, parent};
    else parent->left = new Node<T> {value, nullptr, nullptr, parent};
}

template <typename T>
Tree<T>:: Tree (std::initializer_list<T> list) {
    root=nullptr;
    for (auto value:list) {
        push_back(value);
    }
}
}
