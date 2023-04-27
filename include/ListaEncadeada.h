#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "No.h"
#include "Music.h"

#include <string>

//* Lista Encadeada
template <typename T>
class ListaEncadeada
{
private:
  No<T>* head;
  No<T>* tail;

public:
  ListaEncadeada() //* Initializer Constructor
  {
    this->head = nullptr;
    this->tail = nullptr;
  } 

  ListaEncadeada(T music) //* Default Constructor
  {
    this->head = new No<T>(music);
    this->tail = head;
  }

  ~ListaEncadeada<T>() //* Destructor
  {
    while (head != nullptr)
    {
      No<T>* h = head;
      head = head->getProximo();
      delete h;
    } 
  }

  void print()
  {
    std::cout << "Segue a playlist: \n";
    No<T>* h = head;

    if (head == nullptr) std::cout << "Playlist vazia...\n";
    else{
      while (h)
      {
        std::cout << h->getValue() << std::endl;
        h = h->getProximo();
      }
      std::cout << "\n";
    }
  }

  void insertAtBegin(T music) //* Insert an element at the beginning of the list
  {
    No<T>* novoNo = new No<T>(music);

    if (head == nullptr)
    {
      head = novoNo;
      tail = novoNo;
    }
    else{
      novoNo->setProximo(head);
      head = novoNo;
    }
  }

  void insertAtTheEnd(T music) //* Insert an element at the end of the list
  {
    No<T>* novoNo = new No<T>(music);

    if (head == nullptr)
    {
      head = novoNo;
      tail = novoNo;
    }
    else
    {
      tail->setProximo(head);
      tail = novoNo;
    }
  }

  void removeMusic() //* Remove the music from the list (remove from the end of the list)
  {
    if (!(head == nullptr))
    {
      if (head->getProximo() == nullptr) //* Se houver apenas 1 elemento na lista
      {
        head = nullptr;
      }
      else if (head->getProximo()->getProximo()) //* Se houver apenas 2 elementos na lista
      {
        head->setProximo(nullptr);
      }
      else //* Para mais elementos
      {
        No<T>* antePenultimo = head;
        No<T>* penultimo = head->getProximo();
        No<T>* chain = head->getProximo()->getProximo();

        while (chain)
        {
          No<T>* aux = penultimo;
          penultimo = head->getProximo();
          antePenultimo = aux;
          chain = chain->getProximo();
        } //* Apos o while o penultimo vira o ultimo elemento, entao devemos deletar o prox elemento
        delete antePenultimo->getProximo(); //* Set the next element as a null pointer
        antePenultimo->setProximo(nullptr); //* Update tail value
        tail = antePenultimo;
      }
    }
  }

  bool isInThelist(No<T> val) //* Metodo de busca
  {
    No<T>* h = head;
		
		while(h)
		{
			if(h->getValue() == val)
			{
        return true;
      }	

			h = h->getProximo();
		}
		return false;
  }

  T getCurrentMusic(No<T> val)
  {
    if (isInThelist(val) == true)
    {
      return val;
    }
  }

};


#endif // LISTA_ENCADEADA_H