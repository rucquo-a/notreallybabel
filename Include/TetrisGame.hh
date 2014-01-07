#ifndef __TETRISGAME_HH__
#define __TETRISGAME_HH__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include "TetrisPart.hh"
#include "TetrisMap.hh"
#include "TetrisOver.hh"

class TetrisGame
{
  std::string	_picture;
  sf::RenderWindow	&_window;

public:
  TetrisGame(sf::RenderWindow&);
  ~TetrisGame();
  void	mainGame();
};

#endif
