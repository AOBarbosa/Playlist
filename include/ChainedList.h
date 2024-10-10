#ifndef CHAINED_LIST_H
#define CHAINED_LIST_H

#include "Node.h"
#include <iostream>

template <typename T> 
class ChainedList {

private:
    Node<T>* head;
    Node<T>* tail;

    bool isEmpty() const { return head == nullptr; }

    void removeSingleNode() { 
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    void removeLastNodeFromMultipleNodes() {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current->getNext() != nullptr) {
            previous = current;
            current = current->getNext();
        }

        delete current;
        previous->setNext(nullptr);
        tail = previous;
    }

public:
    ChainedList() : head(nullptr), tail(nullptr) {}

    explicit ChainedList(T value) {
        head = new Node<T>(value);
        tail = head;
    }

    ~ChainedList() {
        while (head != nullptr) {
            Node<T>* current = head;
            head = head->getNext();
            delete current;
        }
    }

    Node<T>* getHead() const { return head; }

    Node<T>* getTail() const { return tail; }

    bool contains(const T& value) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->getValue() == value) {
                return true;
            }
            current = current->getNext();
        }
        return false;
    }

    void setHead(Node<T>* newHead) { head = newHead; }

    void insertAtBeginning(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->setNext(head);
            head = newNode;
        }
    }

    void insertAtEnd(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    void removeLastNode() {
        if (isEmpty()) return;

        if (head == tail) {
            removeSingleNode();
        } else {
            removeLastNodeFromMultipleNodes();
        }
    }

    void print() const {
        if (isEmpty()) {
            std::cout << "The list is empty!\n";
            return;
        }

        std::cout << "Printing all elements:\n";
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->getValue() << std::endl;
            current = current->getNext();
        }
        std::cout << std::endl;
    }
};

#endif
