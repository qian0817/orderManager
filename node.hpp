//
// Created by qianlei on 2020/4/28.
//

#ifndef ORDERMANAGER_NODE_HPP
#define ORDERMANAGER_NODE_HPP

template<typename T>
class node {
public:
    T value;
    node *next;
    node *prev;
    explicit node(T value = T(), node<T> *next = nullptr, node<T> *prev = nullptr);
};

template<typename T>
node<T>::node(T value, node<T> *next, node<T> *prev)
        :value(value), next(next), prev(prev) {
}

#endif //ORDERMANAGER_NODE_HPP