#include "Playlist.h"

/**
 * @file Playlist.cpp
 * 
 * @brief Implementação da Classe Playlist.
*/

/**
 * @brief Construtor de Playlist básico
*/
Playlist::Playlist() {
  this->playlistName = new string;
  this->playlist = ChainedList<Music *>();
}

/**
 * @brief Construtor de Playlist que recebe parametros
 * 
 * @param name Um nome para a Playlist
 * @param playlist Uma ChainedList de endereços de Music
*/
Playlist::Playlist(string name, ChainedList<Music *> playlist)
{
  this->playlistName = new string(name);
  this->playlist = ChainedList<Music *>(playlist);
}

/**
 * @brief Desconstrutor de Playlist
*/
Playlist::~Playlist()
{
  delete this->playlistName;
  this->playlist.~ChainedList();
}

/**
 * @brief Retorna o endereço de uma Music respeitando uma contagem
 * 
 * @param id Um inteiro para contar
 * 
 * @return O endereço de uma Music
*/
Music* Playlist::nextMusicToBePlayed(int id)
{
  Music* temp = new Music();
  for(int i = 0; i < id; i++) {
    if(!i) {
      if(this->playlist.getHead() == nullptr) return nullptr;
      temp = this->playlist.getHead()->getValue();
    }
    else {
      int j = 0;
      Node<Music *> *no = this->playlist.getHead();
      while(j < id) {
        no = no->getNext();
        if(no == nullptr) return nullptr;
        j++;
      }
      temp = no->getValue();
    }
  }
  return temp;
}

/**
 * @brief Salva uma nova Music na Playlist
 * 
 * @param music Um endereço de uma Music
*/
void Playlist::addMusic(Music *music) { this->playlist.insertAtTheEnd(music); }

/**
 * @brief Descarta a última Music da Playlist
*/
void Playlist::removeMusicFromPlaylist() { this->playlist.removeNode(); }

/**
 * @brief Imprime todas as Music da Playlist
 * 
 * @param p Uma Playlist
*/
void Playlist::printPlaylist(Playlist p)
{
  if(p.playlist.getHead()->getNext() == nullptr || p.playlist.getHead() == nullptr) {
    if(p.playlist.getHead() == nullptr) std::cout << "Playlist vazia!" << endl;
    else std::cout << "Fim da playlist." << std::endl;
  } 
  else {
    p.playlist.getHead()->getValue()->printMusic();
    Playlist pTemp;
    pTemp.playlist.setHead(p.playlist.getHead()->getNext());
    pTemp.printPlaylist(pTemp);
  }
}