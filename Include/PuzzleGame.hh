#ifndef __PUZZLEGAME_HH__
#define __PUZZLEGAME_HH__


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "PuzzleSprite.hh"

class PuzzleGame
{
  std::string	_picture;
  sf::RenderWindow	&_window;

public:
  PuzzleGame(sf::RenderWindow&);
  ~PuzzleGame();
  void	mainGame(sf::Image&, std::string);
  void	initImg(std::list<PuzzleSprite*>&, int, sf::Image&);
  void	randImg(std::list<PuzzleSprite*>&);
  void	display(std::list<PuzzleSprite*>&, int);

};

#endif
