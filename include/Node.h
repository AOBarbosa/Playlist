#ifndef NODE_H
#define NODE_H

/**
 * @file Node.h
 * 
 * @brief Cabeçalho e Implementação da Classe Node.
*/
template <typename T> class Node {

private:

  T value; /**< Um valor de tipo genérico*/
  
  Node<T> *next; /**< Um endereço de um Node de tipo genérico*/

public:
/**
 * @brief Construtor de Node
 * 
 * @param v Valor genérico
*/
  Node(T v) {
    this->value = v;
    this->next = nullptr;
  }

/**
 * @brief Retorna o valor de um Node
 * 
 * @return Valor salvo num Node
*/
  T getValue() const { return this->value; }

  void setValue(T v) { this->value = v; }

/**
 * @brief Retorna o endereço do próximo Node salvo num Node
 * 
 * @return Endereço salvo num Node
*/
  Node<T> *getNext() const { return this->next; }

/**
 * @brief Salva o endereço de um Node num Node
 * 
 * @param *prox O endereço do próximo Node que quero salvar
*/
  void setNext(Node *prox) { this->next = prox; }

  void setNode(Node *no)
  {
    this->setValue(no->getValue());
    this->setNext(no->getNext());
  }
};

#endif