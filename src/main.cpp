#include <iostream>
#include <string>

#include "Music.h"
#include "No.h"
#include "ListaEncadeada.h"


int main(int argc, char const *argv[])
{
  std::cout << "Welcome to your newest music playlist!\n";

  std::string option;
  while (option != "-1")
  {
    std::cout << "1) Inform a new music;\n";
    std::cout << "2) Add a new music to a linked list;\n";
    std::cout << "3) Print playlist;\n";
    std::cout << "-1) Exit the program.\n";
    std::cout << "O que deseja fazer? ";
    std::getline(std::cin, option);

    Music* music = new Music();
    std::string musicName;
    std::string artistName;

    if (option == "1")
    {
      std::getline(std::cin, musicName);
      music->setMusicName(musicName);
      
      std::getline(std::cin, artistName);
      music->setArtistName(artistName);


      std::cout << "Music: " << music->getMusicName() << "\nArtist: " << music->getArtistName() << "\n";
    }
     if (option == "2")
     {
      ListaEncadeada<No<Music>>* list = new ListaEncadeada<No<Music>>();

      std::getline(std::cin, musicName);
      music->setMusicName(musicName);
      
      std::getline(std::cin, artistName);
      music->setArtistName(artistName);

      No<Music>* node = new No<Music>(music);
     }
  }

  system("clear || cls");
  

  return 0;
}
