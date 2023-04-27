#include "Playlist.h"
#include "ListaEncadeada.h"

#include <iostream>

Playlist::Playlist()
{
  this->playlistName = new std::string;
  this->playlist = ListaEncadeada<Music*>();
}

Playlist::Playlist(std::string name, ListaEncadeada<Music*> playlist)
{
  this->playlistName = new std::string(name);
  this->playlist = ListaEncadeada<Music*>(playlist);
}

Playlist::~Playlist()
{
  std::cout << "PLaylist removida!\n";
}

void Playlist::addMusic(Music* music)
{
  this->playlist.insertAtTheEnd(music);
}

void Playlist::removeMusicFromPlaylist()
{
  this->playlist.removeMusic();
}