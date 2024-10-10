#ifndef MUSIC_H
#define MUSIC_H
#include <string>

using namespace std;

class Music {

private:
  string *musicName; 
  string *artistName; 

public:

  Music();

  Music(string music, string artist);

  ~Music();

  string getMusicName() const;

  string getArtistName() const;

  void setMusicName(string music);

  void setArtistName(string artist);

  void printMusic();
};

#endif
