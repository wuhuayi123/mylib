#pragma once
#include <iostream>

namespace mylib {

template <class T>
class Node {
public:
    T data_;
    Node* next_;
    Node(T data) : next_(nullptr), data_(data){};
    ~Node();
};

template <class T>
class List {
private:
    Node<T>* head_;
    Node<T>* tail_;
    Node<T>* cur_;
    unsigned int length_;

public:
    List();
    ~List();
    List(const List& copy);
    List(const List&& copy);

public:
    void Echo();
    bool InsertAfter(const Node<T>* item);
    bool Push(T data);
    bool DeleteAfter();
    unsigned int Length();
    unsigned int Position();
    Node<T>* Search(T);
    bool Clear();
    Node<T>* Cur();
    Node<T>* Next();
};

template <class T>
List<T>::List() {
    head_ = tail_ = cur_ = nullptr;
    length_ = 0;
}

template <class T>
List<T>::~List() {}

template <class T>
List<T>::List(const List& copy) {}

template <class T>
List<T>::List(const List&& copy) {}

template <class T>
void List<T>::Echo() {
    Node<T>* pos = head_;
    for (auto count = 0; count < length_; count++) {
        std::cout << pos->data_ << std::endl;
        pos = pos->next_;
    }
}

template <class T>
bool List<T>::Push(T data) {
    auto item = new Node<T>(data);
    if (!head_) {
        head_ = item;
    }

    if (!tail_) {
        tail_ = item;
    } else {
        tail_->next_ = item;
    }

    tail_ = item;

    length_++;
}

template <class T>
bool List<T>::InsertAfter(const Node<T>* item) {}

template <class T>
bool List<T>::DeleteAfter() {}

template <class T>
unsigned int List<T>::Length() {
    return length_;
}

// Todo
template <class T>
Node<T>* List<T>::Cur() {
    if (cur_) {
        return cur_;
    } else {
        return head_;
    }
}

// Todo
template <class T>
Node<T>* List<T>::Next() {
    if (!cur_) {
        return nullptr;
    } else {
        return cur_->next_;
    }
}

template <class T>
Node<T>* List<T>::Search(T data) {
    auto pos = head_;
    for (auto count = 0; count < length_; count++) {
        std::cout << pos->data_ << std::endl;
        if (pos->data_ == data) {
            return pos;
        };
        pos = pos->next_;
    }

    return nullptr;
}

template <class T>
bool List<T>::Clear() {
    auto pos = head_;
    for (auto count = 0; count < length_; count++) {
        delete (pos);
        pos = pos->next_;
    }
    head_ = tail_ = cur_ = nullptr;
    length_ = 0;
}
}  // namespace mylib
