#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>

#include "ListaEncadeada.h"
#include "Music.h"

class Playlist
{
private:
  std::string* playlistName;
  ListaEncadeada<Music*> playlist;


public:
  Playlist();
  Playlist(std::string name, ListaEncadeada<Music*> playlist);
  ~Playlist();

  void addMusic(Music* music);
  void removeMusicFromPlaylist();
};


#endif //* PLAYLIST_H