#pragma once
#include <iostream>

namespace mylib {

template <class T>
class Node {
public:
    T data_;
    Node* next_;
    Node(T data) : next_(nullptr), data_(data){};
    ~Node(){};
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
    bool InsertAfter(int position, Node<T>* item);
    bool Push(T data);
    bool DeleteAfter(int position);
    unsigned int Length();
    Node<T>* Search(T);
    bool Clear();
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
bool List<T>::InsertAfter(int position, Node<T>* item) {
    auto pos = head_;
    for (auto count = 0; count < length_; count++) {
        if (count == position) {
            auto pre_next = pos->next_;
            pos->next_ = item;
            item->next_ = pre_next;
            return true;
        };
        pos = pos->next_;
    }

    tail_->next_ = item;
    tail_ = item;
}

template <class T>
bool List<T>::DeleteAfter(int position) {
    auto pos = head_;
    for (auto count = 0; count < length_; count++) {
        if (count == position) {
            auto pre_next = pos->next_;
            pos->next_ = pre_next->next_;
            delete (pre_next);
            return true;
        };
        pos = pos->next_;
    }

    return false;
}

template <class T>
unsigned int List<T>::Length() {
    return length_;
}

template <class T>
Node<T>* List<T>::Search(T data) {
    Node<T>* pos = head_;
    for (auto count = 0; count < length_; count++) {
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
