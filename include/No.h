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
  No<T> (T val)
  {
    this->value = val;
    this->proximo = nullptr;
  }
 
  T getValue() const { return this->value; }

  No<T>* getProximo() const { return this->proximo; } 
  
  void setProximo(No* prox) { this->proximo = prox; }
  
};

#endif