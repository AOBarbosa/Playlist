#include "Music.h"

Music::Music()
{
  musicName = new std::string;
  artistName = new std::string;
}

Music::Music(std::string music, std::string artist)
{
  this->musicName = new std::string(music);
  this->artistName = new std::string(artist);
}

Music::~Music()
{
  delete musicName;
  delete artistName;
}

std::string Music::getMusicName() const
{
  return *musicName;
}

std::string Music::getArtistName() const
{
  return *artistName;
}

void Music::setMusicName(std::string music)
{
  *this->musicName = music;
}

void Music::setArtistName(std::string artist)
{
  *this->artistName = artist;
}