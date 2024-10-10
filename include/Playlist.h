#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "ChainedList.h"
#include "Music.h"
#include <string>


class Playlist {
private:
    std::string* playlistName; 
    ChainedList<Music*> playlist;

  public:

      Playlist();

      Playlist(std::string name, ChainedList<Music*> playlist);

      ~Playlist();

      Music* nextMusicToBePlayed(int id);

      void addMusic(Music* music);

      void removeMusicFromPlaylist();

      void printPlaylist(Playlist p);

      void setPlaylist(ChainedList<Music*> playlist);
};

#endif
