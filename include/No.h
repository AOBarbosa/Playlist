#ifndef NO_H
#define NO_H

#include <string>

//* Nó class
template <typename T>
class No
{
private:
  T value;
  No<T>* proximo;

public:
  No (T val)
  {
    this->value = "";
    this->proximo = nullptr;
  }

  No (T val)
  {
    this->value = val;
    this->proximo = nullptr;
  }
 
  T getValue() const { return this->value; }

  No* getProximo() const { return this->proximo; } 
  
  T setProximo(No* prox) { this->proximo = prox; }
  
};

#endif