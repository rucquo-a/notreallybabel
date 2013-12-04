#ifndef __PUZZLEGAME_HH__
#define __PUZZLEGAME_HH__


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class PuzzleGame
{
  std::string	_picture;
  sf::RenderWindow	&_window;

public:
  PuzzleGame(sf::RenderWindow&);
  ~PuzzleGame();
  void	mainGame();


};

#endif
