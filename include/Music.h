#ifndef MUSIC_H
#define MUSIC_H
#include <string>

/**
 * @file Music.h
 * 
 * @brief Cabeçalho da Classe Music.
*/
class Music {

private:
  std::string musicName; /**< Um nome de música*/
  std::string artistName; /**< Um nome de artista*/

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
  Music(std::string music, std::string artist);

/**
 * @brief Desconstrutor de Music
*/
  ~Music();

/**
 * @brief Retorna o nome de uma música
 * 
 * @return O nome de uma música
*/
  std::string getMusicName();

/**
 * @brief Retorna o nome de um artista
 * 
 * @return O nome de um(a) artista
*/
  std::string getArtistName();

/**
 * @brief Salva o nome de uma música numa Music
 * 
 * @param music Nome de uma música
*/
  void setMusicName(std::string music);

/**
 * @brief Salva o nome de um(a) artista numa Music
 * 
 * @param music Nome de um(a) artista
*/
  void setArtistName(std::string artist);

/**
 * @brief Imprime os valores associados a uma Music
*/
  void printMusic();
};
#endif