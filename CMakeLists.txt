# arquivo CMakeLists.txt
cmake_minimum_required(VERSION 3.26.1) 
project(Playlist VERSION 0.1 LANGUAGES CXX )
# flags de compilação, vc pode colocar aqui # o addres sanitizer por exemplo 
set ( CMAKE_CXX_FLAGS "-Wall" )
# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h" 
include_directories( include )
# Cria um executável com nome "program" com base nos arquivos main.cpp e func.cpp 
add_executable( program
  src/main.cpp
  src/Music.cpp
  src/Playlist.cpp
  src/Funcs.cpp )
# define C++14 standard
set_property(TARGET program PROPERTY CXX_STANDARD 14)