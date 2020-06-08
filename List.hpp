//
// Created by qianlei on 2020/4/28.
//

#ifndef ORDERMANAGER_LIST_HPP
#define ORDERMANAGER_LIST_HPP

#include "Node.hpp"

template<typename T>
class List {
private:
    Node<T> *head = new Node<T>(T());

    //链表迭代器
    class iterator {
    private:
        Node<T> *ptr;
    public:
        explicit iterator(Node<T> *ptr);
        T &operator*() const;
        T *operator->() const;
        bool operator==(const List<T>::iterator &iter);
        bool operator!=(const List<T>::iterator &iter);
        iterator &operator++();
        /**
         * 删除迭代器指向的结点
         */
        void remove();
    };

public:
    /**
    * 在链表头添加结点
    * @param value 添加的结点的内容
    */
    void add(T value);
    int size() const;
    iterator begin();
    iterator end();
    ~List();
};

template<typename T>
bool List<T>::iterator::operator==(const List<T>::iterator &iter) {
    return iter.ptr == ptr;
}

template<typename T>
T &List<T>::iterator::operator*() const {
    return ptr->value;
}

template<typename T>
bool List<T>::iterator::operator!=(const List<T>::iterator &iter) {
    return !(*this == iter);
}

template<typename T>
typename List<T>::iterator &List<T>::iterator::operator++() {
    ptr = ptr->next;
    return *this;
}

template<typename T>
List<T>::iterator::iterator(Node<T> *ptr):ptr(ptr) {}

template<typename T>
T *List<T>::iterator::operator->() const {
    return &(ptr->value);
}

template<typename T>
void List<T>::iterator::remove() {
    Node<T> *temp = ptr;
    ptr->prev->next = ptr->next;
    if (ptr->next != nullptr) {
        ptr->next->prev = ptr->prev;
    }
    ptr = ptr->prev;
    delete temp;
}

template<typename T>
void List<T>::add(T value) {
    auto *temp = new Node<T>(value, head->next, head);
    head->next = temp;
    if (temp->next != nullptr) {
        temp->next->prev = temp;
    }
}

template<typename T>
List<T>::~List() {
    while (head != nullptr) {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
typename List<T>::iterator List<T>::begin() {
    return List::iterator(head->next);
}

template<typename T>
typename List<T>::iterator List<T>::end() {
    return List::iterator(nullptr);
}

template<typename T>
int List<T>::size() const {
    Node<T> *temp = head->next;
    int size = 0;
    while (temp != nullptr) {
        temp = temp->next;
        size++;
    }
    return size;
}

#endif //ORDERMANAGER_LIST_HPP