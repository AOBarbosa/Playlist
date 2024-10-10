#ifndef CHAINED_LIST_H
#define CHAINED_LIST_H

#include "Node.h"
#include <iostream>

using namespace std;

template <typename T> class ChainedList {

  private:
    Node<T> *head;
    Node<T> *tail;

    bool isEmptyList() const { return head == nullptr; }

    bool isSingleNode() const { return head->getNext() == nullptr; }

    bool hasTwoNodes() const { return head->getNext()->getNext() == nullptr; }

    void clearHead() { head->setValue(nullptr); }

    void removeSecondNode() { head->setNext(nullptr); }

    void removeLastFromMultipleNodes() 
    {
      Node<T>* preLast = this->head;
      Node<T>* last = head->getNext();
      Node<T>* next = last->getNext();

      while (next != nullptr) {
          preLast = last;
          last = next;
          next = next->getNext();
      }

      delete last;
      preLast->setNext(nullptr);
      tail = preLast;
    }

  public:
    ChainedList()
    {
      this->head = nullptr;
      this->tail = nullptr;
    }

    ChainedList(T type)
    {
      this->head = new Node<T*>(type);
      this->tail = head;
    }

    ~ChainedList<T>()
    {
      while (head != nullptr) {
        Node<T> *h = head;
        head = head->getNext();
        delete h;
      }
    }

    Node<T>* getHead() { return this->head; }

    Node<T>* getTail() { return this->tail; }

    T getCurrentValue(Node<T> no) 
    { 
      if (isInThelist(no) == true) return no; 
    
      return nullptr;
    }

    bool isInThelist(Node<T> no)
    {
      Node<T> *h = head;

      while (h) {
        if (h->getValue() == no) return true;
        h = h->getNext();
      }

      return false;
    }

    void setHead(Node<T> *no){ this->head = no; }

    void insertAtBegin(T type) 
    {
      Node<T> *novoNo = new Node<T>(type);

      if (this->isEmptyList()) {
        this->head = novoNo;
        this->tail = novoNo;
      } else {
        novoNo->setNext(head);
        this->head = novoNo;
      }
    }

    void insertAtTheEnd(T value)
    {
      Node<T> *novoNo = new Node<T>(value);

      if (this->isEmptyList()) {
        this->head = novoNo;
        this->tail = novoNo;
      } else {
        this->tail->setNext(head);
        this->tail = novoNo;
      }
    }

    void removeNode()
    {
      if (this->isEmpty()) return;

      if (isSingleNode()) {
        clearHead();
      } 
      else if (hasTwoNodes()) {
          removeSecondNode();
      } 
      else {
          removeLastFromMultipleNodes();
      }
    }

    void print()
    {
      std::cout << "\nImprimindo todos os elementos...\n";
      Node<T>* h = this->head;

      if(this->isEmptyList()) {
        std::cout << "A lista NAO possui elementos!!\n";
        return;
      }

      while(h) {
        std::cout << h->getValue() << std::endl;
        h = h->getNext();
      }
      std::cout << std::endl;
    }
};

#endif