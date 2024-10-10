#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {

private:
    T value; 
    Node<T>* next; 

public:
    Node(T value) : value(value), next(nullptr) {}

    T getValue() const { return value; }

    void setValue(T value) { this->value = value; }

    Node<T>* getNext() const { return next; }

    void setNext(Node<T>* next) { this->next = next; }

    void setNode(const Node<T>* node) {
        this->value = node->getValue();
        this->next = node->getNext();
    }
};

#endif
