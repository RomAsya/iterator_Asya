#include "node.hpp"

namespace BSTree {
template<typename T>
class iterator;

template <typename T>
class pre_iterator;

template <typename T>
class post_iterator;

template<typename T>
class iterator {

    using pointer = T *;
    using reference = T &;
    using value_type = T;

public:
 
    virtual iterator& operator++()=0;

    virtual reference operator*() =0;

    //virtual iterator operator++(int) = 0;

    //pointer operator->() const;

    //iterator operator++(int);

    //friend bool operator==(const iterator&, const iterator&);

    //friend void swap(iterator& lhs, iterator& rhs);

private:
    Node<T>* ptr;
};
template <typename T>
class pre_iterator : public iterator<T> {
public:
    pre_iterator();
    auto pre_detour()->pre_iterator<T>& ;
    virtual auto operator++() ->pre_iterator<T>&;
    virtual auto operator *() -> T&;
    auto operator =( pre_iterator &)->pre_iterator<T>&;
    pre_iterator(Node<T>* ptr);
    template <typename T1>
        auto friend operator!=( pre_iterator<T1>& it1, pre_iterator<T1>& it2) -> bool
        {
            if(it1.ptr->data!=it2.ptr->data) return true;
                return false;
        }
private:
    Node<T>* ptr;
};

template <typename T>
class post_iterator : public iterator <T> {
public:
     post_iterator();
     post_iterator(Node<T>* ptr);
     auto post_detour()->post_iterator<T>&;
     virtual auto operator *() -> T&;
     virtual auto operator++() ->post_iterator<T>&;
     auto operator =( post_iterator &)->post_iterator<T>&;
 template <typename T2>
        auto friend operator!=( post_iterator<T2>& it1, post_iterator<T2>& it2) -> bool
        {
            if(it1.ptr->data!=it2.ptr->data) return true;
                return false;
        }

private:
        Node<T> * ptr;
};

template <typename T>
auto pre_iterator<T>:: operator=( pre_iterator&
iter)->pre_iterator<T> &  {
    this->ptr=iter.ptr;
    return *this;
}

template <typename T>
auto post_iterator<T>:: operator=( post_iterator&
iter)->post_iterator<T> &  {
    this->ptr=iter.ptr;
    return *this;
}

template <typename T>
pre_iterator<T>::pre_iterator() :
    ptr {nullptr}
{}

template <typename T>
post_iterator<T>::post_iterator(Node<T>* ptr)
{
    this->ptr = ptr;
}

template <typename T>
post_iterator<T>::post_iterator() :
    ptr {nullptr}
{}

template <typename T>
pre_iterator<T>::pre_iterator(Node<T>* ptr)
{
    this->ptr = ptr;
}


template <typename T>
auto pre_iterator<T>:: pre_detour ()->pre_iterator<T>& {
    if (ptr->left!=nullptr) {
        ptr = ptr->left;
        return *this;
    }
    if (ptr->right!=nullptr) {
        ptr = ptr->right;
        return *this;
    }
    if (ptr->parent==nullptr) {
        ptr=nullptr;
        return *this;
    }
    Node<T> *curr = ptr;
    while(1) {
        if(curr->parent == nullptr) {
            ptr=nullptr;
            return *this;
        }
        if((curr->parent->left == curr) && (curr->parent->right!=
nullptr)) {
            ptr = curr->parent->right;
            return *this;
        }
        curr = curr->parent;
    }
}

template <typename T>
auto post_iterator<T>:: post_detour ()->post_iterator<T>& {
        if (ptr->parent == nullptr) { ptr = nullptr; return *this;}
        if (ptr->parent->right == ptr){ptr = ptr->parent; return *this;}
        if ((ptr->parent->left == ptr)&&(ptr->parent->right == nullptr)){
                ptr = ptr->parent; return *this;
        }
        ptr = ptr->parent->right;
        Node<T>* curr = ptr;
        while(1){
                if (ptr->left != nullptr) { ptr = ptr->left; continue;}
                if (ptr->right != nullptr) ptr = ptr->right;
                else break;
        }
        return *this;
}


template <typename T>
auto pre_iterator<T>:: operator++() ->pre_iterator<T> &  {
    this->pre_detour();
    return *this;
}

template <typename T>
auto post_iterator<T>:: operator++() ->post_iterator<T> &  {
    this->post_detour();
    return *this;
}

template <typename T>
auto pre_iterator<T>::operator *() ->T & {
    return ptr->data;
}

template <typename T>
auto post_iterator<T>::operator *() ->T & {
    return ptr->data;
}
}
