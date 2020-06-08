//
// Created by qianlei on 2020/4/28.
//

#ifndef ORDERMANAGER_NODE_HPP
#define ORDERMANAGER_NODE_HPP

template<typename T>
class Node {
public:
    T value;
    Node *next;
    Node *prev;
    explicit Node(T value, Node<T> *next = nullptr, Node<T> *prev = nullptr);
};

template<typename T>
Node<T>::Node(T value, Node<T> *next, Node<T> *prev)
        :value(value), next(next), prev(prev) {
}

#endif //ORDERMANAGER_NODE_HPP