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
  this->musicName = "";
  this->artistName = "";
}

/**
 * @brief Construtor de Music que recebe parametros
 * 
 * @param music Um nome de música
 * @param artist Um nome de autor de música(s)
*/
Music::Music(std::string music, std::string artist)
{
  this->musicName = music;
  this->artistName = artist;
}

/**
 * @brief Desconstrutor de Music
*/
Music::~Music(){}

/**
 * @brief Retorna o nome de uma música
 * 
 * @return O nome de uma música
*/
std::string Music::getMusicName() { return this->musicName; }

/**
 * @brief Retorna o nome de um artista
 * 
 * @return O nome de um(a) artista
*/
std::string Music::getArtistName() { return this->artistName; }

/**
 * @brief Salva o nome de uma música numa Music
 * 
 * @param music Nome de uma música
*/
void Music::setMusicName(std::string music) { this->musicName = music; }

/**
 * @brief Salva o nome de um(a) artista numa Music
 * 
 * @param music Nome de um(a) artista
*/
void Music::setArtistName(std::string artist) { this->artistName = artist; }

/**
 * @brief Imprime os valores associados a uma Music
*/
void Music::printMusic() {
  std::cout << "Music: " << getMusicName() << std::endl;
  std::cout << "Artist: " << getArtistName() << std::endl;
}