#include "Music.h"
#include <iostream>

/**
 * @file Music.cpp
 * 
 * @brief Implementação da Classe Music.
*/

/**
 * @brief Construtor de Music básico
*/
Music::Music()
{
  this->musicName = new string;
  this->artistName = new string;
}

/**
 * @brief Construtor de Music que recebe parametros
 * 
 * @param music Um nome de música
 * @param artist Um nome de autor de música(s)
*/
Music::Music(string music, string artist)
{
  this->musicName = new string(music);
  this->artistName = new string(artist);
}

/**
 * @brief Desconstrutor de Music
*/
Music::~Music()
{
  delete this->musicName;
  delete this->artistName;
}

/**
 * @brief Retorna o nome de uma música
 * 
 * @return O nome de uma música
*/
string Music::getMusicName() const { return *(this->musicName); }

/**
 * @brief Retorna o nome de um artista
 * 
 * @return O nome de um(a) artista
*/
string Music::getArtistName() const { return *(this->artistName); }

/**
 * @brief Salva o nome de uma música numa Music
 * 
 * @param music Nome de uma música
*/
void Music::setMusicName(string music) { *(this->musicName) = music; }

/**
 * @brief Salva o nome de um(a) artista numa Music
 * 
 * @param music Nome de um(a) artista
*/
void Music::setArtistName(string artist) { *(this->artistName) = artist; }

/**
 * @brief Imprime os valores associados a uma Music
*/
void Music::printMusic() {
  cout << "Music: " << getMusicName() << endl;
  cout << "Artist: " << getArtistName() << endl;
}