#include "Music.h"
#include <iostream>

Music::Music()
{
  this->musicName = new string;
  this->artistName = new string;
}

Music::Music(string music, string artist)
{
  this->musicName = new string(music);
  this->artistName = new string(artist);
}

Music::~Music()
{
  delete this->musicName;
  delete this->artistName;
}

string Music::getMusicName() const { return *(this->musicName); }

string Music::getArtistName() const { return *(this->artistName); }

void Music::setMusicName(string music) { *(this->musicName) = music; }

void Music::setArtistName(string artist) { *(this->artistName) = artist; }

void Music::printMusic() {
  cout << "Music: " << getMusicName() << endl;
  cout << "Artist: " << getArtistName() << endl;
}