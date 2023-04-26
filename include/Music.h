#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <string>

class Music
{
private:
  std::string *musicName;
  std::string *artistName;

public:
  Music(); //* Default Constructor
  Music(std::string music, std::string artist); //* Constructor
  ~Music(); //* Destructor

  std::string getMusicName() const;
  std::string getArtistName() const;

  void setMusicName(std::string music);
  void setArtistName(std::string artist);
};

#endif // MUSIC_H