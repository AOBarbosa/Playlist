#include <iostream>
#include <string>

#include "Funcs.h"
#include "Music.h"
#include "Node.h"
#include "Playlist.h"
#include "ChainedList.h"


int main(int argc, char const *argv[])
{
  ChainedList<Playlist*> playlist;
  ChainedList<Music*> musics;

  std::string option;
  while (option != "0")
  {
    std::cout << "==========================-Menu-======================" << std::endl;
    std::cout << "1) Manage musics;\n";
    std::cout << "2) Manage playlists;\n";
    std::cout << "3) Manage musics in playlists;\n";
    std::cout << "0) Exit the program.\n";
    std::cout << "======================================================" << std::endl;
    std::cout << "Choose your next action: ";
    std::getline(std::cin, option);

    Music* music = new Music();
    std::string musicName;
    std::string artistName;

    if (option == "1")
    {
      manageMusics(musics);
    }

     if (option == "2")
     {
      ChainedList<Music*> list;

      std::getline(std::cin, musicName);
      
      std::getline(std::cin, artistName);
      music->setArtistName(artistName);

      list.insertAtTheEnd(music);
     }
  }

  system("clear || cls");
  

  return 0;
}
