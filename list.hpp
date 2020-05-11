//
// Created by qianlei on 2020/4/28.
//

#ifndef ORDERMANAGER_LIST_HPP
#define ORDERMANAGER_LIST_HPP

#include "node.hpp"

template<typename T>
class list {
private:
    node<T> *head = new node<T>();;

    //链表迭代器
    class iterator {
    private:
        node<T> *ptr;
    public:
        explicit iterator(node<T> *ptr);
        T &operator*() const;
        T *operator->() const;
        bool operator==(const list<T>::iterator &iter);
        bool operator!=(const list<T>::iterator &iter);
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
    ~list();
};

template<typename T>
bool list<T>::iterator::operator==(const list<T>::iterator &iter) {
    return iter.ptr == ptr;
}

template<typename T>
T &list<T>::iterator::operator*() const {
    return ptr->value;
}

template<typename T>
bool list<T>::iterator::operator!=(const list<T>::iterator &iter) {
    return !(*this == iter);
}

template<typename T>
typename list<T>::iterator &list<T>::iterator::operator++() {
    ptr = ptr->next;
    return *this;
}

template<typename T>
list<T>::iterator::iterator(node<T> *ptr):ptr(ptr) {}

template<typename T>
T *list<T>::iterator::operator->() const {
    return &(ptr->value);
}


template<typename T>
void list<T>::iterator::remove() {
    node<T> *temp = ptr;
    ptr->prev->next = ptr->next;
    if (ptr->next != nullptr) {
        ptr->next->prev = ptr->prev;
    }
    ptr = ptr->prev;
    delete temp;
}

template<typename T>
void list<T>::add(T value) {
    auto *temp = new node<T>(value, head->next, head);
    head->next = temp;
    if (temp->next != nullptr) {
        temp->next->prev = temp;
    }
}

template<typename T>
list<T>::~list() {
    while (head != nullptr) {
        node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
typename list<T>::iterator list<T>::begin() {
    return list::iterator(head->next);
}

template<typename T>
typename list<T>::iterator list<T>::end() {
    return list::iterator(nullptr);
}

template<typename T>
int list<T>::size() const {
    node<T> *temp = head->next;
    int size = 0;
    while (temp != nullptr) {
        temp = temp->next;
        size++;
    }
    return size;
}

#endif //ORDERMANAGER_LIST_HPP