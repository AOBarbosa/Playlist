#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "ChainedList.h"
#include "Music.h"

/**
 * @file Playlist.h
 * 
 * @brief Cabeçalho da Classe Playlist.
*/
class Playlist {

private:
  string *playlistName; /**< Um endereço de um nome de uma Playlist*/
  ChainedList<Music*> playlist; /**< Uma ChainedList de endereços de Music*/
public:
/**
 * @brief Construtor de Playlist básico
*/
  Playlist();

/**
 * @brief Construtor de Playlist que recebe parametros
 * 
 * @param name Um nome para a Playlist
 * @param playlist Uma ChainedList de endereços de Music
*/
  Playlist(string name, ChainedList<Music*> playlist);

/**
 * @brief Desconstrutor de Playlist
*/
  ~Playlist();

/**
 * @brief Retorna o endereço de uma Music respeitando uma contagem
 * 
 * @param id Um inteiro para contar
 * 
 * @return O endereço de uma Music
*/
  Music* nextMusicToBePlayed(int id);

/**
 * @brief Salva uma nova Music na Playlist
 * 
 * @param music Um endereço de uma Music
*/
  void addMusic(Music* music);

/**
 * @brief Descarta a última Music da Playlist
*/
  void removeMusicFromPlaylist();

/**
 * @brief Imprime todas as Music da Playlist
 * 
 * @param p Uma Playlist
*/
  void printPlaylist(Playlist p);
};

#endif