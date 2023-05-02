#ifndef MUSIC_H
#define MUSIC_H
#include <string>

using namespace std;

/**
 * @file Music.h
 * 
 * @brief Cabeçalho da Classe Music.
*/
class Music {

private:
  string *musicName; /**< Um endereço de um nome de música*/
  string *artistName; /**< Um endereço de um nome de artista*/

public:
/**
 * @brief Construtor de Music básico
*/
  Music();

/**
 * @brief Construtor de Music que recebe parametros
 * 
 * @param music Um nome de música
 * @param artist Um nome de autor de música(s)
*/
  Music(string music, string artist);

/**
 * @brief Desconstrutor de Music
*/
  ~Music();

/**
 * @brief Retorna o nome de uma música
 * 
 * @return O nome de uma música
*/
  string getMusicName() const;

/**
 * @brief Retorna o nome de um artista
 * 
 * @return O nome de um(a) artista
*/
  string getArtistName() const;

/**
 * @brief Salva o nome de uma música numa Music
 * 
 * @param music Nome de uma música
*/
  void setMusicName(string music);

/**
 * @brief Salva o nome de um(a) artista numa Music
 * 
 * @param music Nome de um(a) artista
*/
  void setArtistName(string artist);

/**
 * @brief Imprime os valores associados a uma Music
*/
  void printMusic();
};
#endif