#ifndef CHAINED_LIST_H
#define CHAINED_LIST_H

#include "Node.h"
#include <iostream>

/**
 * @file ChainedList.h
 * 
 * @brief Cabeçalho e Implementação da Classe ChainedList.
*/
template <typename T> class ChainedList {

private:
  Node<T> *head; /**< O endereço do primeiro Node de tipo genérico da ChainedList*/
  Node<T> *tail; /**< O endereço do último Node de tipo genérico da ChainedList*/

public:
/**
 * @brief Construtor de ChainedList básico
*/
  ChainedList()
  {
    this->head = nullptr;
    this->tail = nullptr;
  }

/**
 * @brief Construtor de ChainedList que recebe parâmetro
 * 
 * @param type Um valor de tipo genérico
*/
  ChainedList(T type) //* Default Constructor
  {
    this->head = new Node<T*>(type);
    this->tail = head;
  }

/**
 * @brief Desconstrutor de ChainedLIst
*/
  ~ChainedList<T>() //* Destructor
  {
    while (head != nullptr) {
      Node<T> *h = head;
      head = head->getNext();
      delete h;
    }
  }

/**
 * @brief Retorna o endereço do primeiro Node de tipo genérico da ChainedList
 * 
 * @return Endereço do primeiro Node de tipo genérico da ChainedList
*/
  Node<T>* getHead()
  {
    return this->head;
  }

/**
 * @brief Retorna o endereço do último Node de tipo genérico da ChainedList
 * 
 * @return Endereço do último Node de tipo genérico da ChainedList
*/
  Node<T>* getTail()
  {
    return this->tail;
  }

/**
 * @brief Retorna o valor de um Node se o metodo de busca permitir
 * 
 * @param no Um Node de tipo genérico
 * 
 * @return Um valor de tipo genérico
*/
  T getCurrentValue(Node<T> no) {
    if (isInThelist(no) == true) return no;
  }

/**
 * @brief Metodo de busca de valores na ChainedList
 * 
 * @param no Um Node de tipo genérico
 * 
 * @return Um valor bool
*/
  bool isInThelist(Node<T> no)
  {
    Node<T> *h = head;

    while (h) {
      if (h->getValue() == no) return true;
      h = h->getNext();
    }
    return false;
  }

/**
 * @brief Salva um novo endereço para ser o primeiro Node de tipo genérico da ChainedList
 * 
 * @param no Um endereço de Node de tipo genérico
*/
  void setHead(Node<T> *no)
  {
    this->head = no;
  }

/**
 * @brief Insere um novo Node no começo da ChainedList
 * 
 * @param type Um valor de tipo genérico
*/
  void insertAtBegin(T type) //* 
  {
    Node<T> *novoNo = new Node<T>(type);

    if (head == nullptr) {
      head = novoNo;
      tail = novoNo;
    } else {
      novoNo->setNext(head);
      head = novoNo;
    }
  }

/**
 * @brief Insere um novo Node no final da ChainedList
 * 
 * @param value Um valor de tipo genérico
*/
  void insertAtTheEnd(T value)
  {
    Node<T> novoNo(value);

    if (head == nullptr) {
      head = &novoNo;
      tail = &novoNo;
    } else {
      tail->setNext(head);
      tail = &novoNo;
    }
  }

/**
 * @brief Remove o último Node da ChainedList
*/
  void removeNode()
  {
    if (!(head != nullptr)) {
      if (head->getNext() == nullptr)
      {
        head->setValue(nullptr);
      } 
      else if (head->getNext()->getNext() == nullptr)
      {
        head->setNext(nullptr);
      } 
      else
      {
        Node<T> *antePenultimo = head;
        Node<T> *penultimo = head->getNext();
        Node<T> *chain = head->getNext()->getNext();

        while (chain) 
        {
          Node<T> *aux = penultimo;
          penultimo = head->getNext();
          antePenultimo = aux;
          chain = chain->getNext();
        }
        delete antePenultimo->getNext();
        antePenultimo->setNext(nullptr);
        tail = antePenultimo;
      }
    }
  }

/**
 * @brief Imprime os Node de uma ChainedList
*/
  void print()
  {
    std::cout << "\nImprimindo todos os elementos...\n";
		Node<T>* h = this->head;

		if(head == nullptr) std::cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(h)
			{
				std::cout << h->getValue() << std::endl;
				h = h->getNext();
			}
			std::cout << std::endl;
		}
  }
};

#endif