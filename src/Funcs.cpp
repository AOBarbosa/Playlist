#include <iostream>
#include <string>

#include "ChainedList.h"
#include "Music.h"
#include "Playlist.h"
#include "Funcs.h"

void manageMusics(ChainedList<Music*> musics)
{
  std::string action;
  while (action != "0")
  {
    std::cout << "====================-Manage Musics-===================" << std::endl;
    std::cout << "1) Register new music;\n";
    std::cout << "2) Remove music;\n";
    std::cout << "3) List musics;\n";
    std::cout << "0) Back;\n";
    std::cout << "======================================================" << std::endl;
    std::cout << "Choose your next action: ";
    std::getline(std::cin, action);

    
    Music* music1 = new Music("Aerials", "System of a Down");
    Music* music2 = new Music("Deixa Acontecer", "Grupo Revelação");
    Music* music3 = new Music("Bones", "Imagine Dragon");

    musics.insertAtTheEnd(music1);
    musics.insertAtTheEnd(music2);
    musics.insertAtTheEnd(music3);

    if (action == "1")
    {
      Music* music = new Music();
      std::string musicName;
      std::string artistName;

      std::getline(std::cin, musicName);
      std::getline(std::cin, artistName);

      musics.insertAtTheEnd(music);

      system("clear || cls");
    }

    if (action == "2")
    {
      musics.removeNode();

      system("clear || cls");

    }

    if (action == "3")
    {
      musics.getTail()->getValue()->printMusic();
    }
    
    

    if (action == "0") break;
  }

  system("clear || cls");
}