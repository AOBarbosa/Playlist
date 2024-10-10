#include "Playlist.h"
#include <iostream>

Playlist::Playlist() 
    : playlistName(new std::string), playlist(ChainedList<Music*>()) {}

Playlist::Playlist(std::string name, ChainedList<Music*> playlist) 
    : playlistName(new std::string(name)), playlist(playlist) {}

Playlist::~Playlist() {
    delete playlistName; 
}

Music* Playlist::nextMusicToBePlayed(int id) {
    if (id < 0 || playlist.getHead() == nullptr) return nullptr;

    Node<Music*>* currentNode = playlist.getHead();
    for (int i = 0; i < id; ++i) {
        currentNode = currentNode->getNext();
        if (currentNode == nullptr) return nullptr; 
    }

    return currentNode->getValue(); 
}

void Playlist::addMusic(Music* music) {
    playlist.insertAtEnd(music);
}

void Playlist::removeMusicFromPlaylist() {
    playlist.removeLastNode();
}

void Playlist::printPlaylist(Playlist p) {
    Node<Music*>* currentNode = p.playlist.getHead();
    
    if (currentNode == nullptr) {
        std::cout << "Playlist vazia!" << std::endl;
        return;
    }

    while (currentNode != nullptr) {
        currentNode->getValue()->printMusic();
        currentNode = currentNode->getNext();
    }
    
    std::cout << "Fim da playlist." << std::endl;
}

void Playlist::setPlaylist(ChainedList<Music*> newPlaylist) {
    Node<Music*>* currentNode = newPlaylist.getHead();
    while (currentNode != nullptr) {
        playlist.insertAtEnd(currentNode->getValue());
        currentNode = currentNode->getNext();
    }
}
