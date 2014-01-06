#ifndef __PUZZLEGAME_HH__
#define __PUZZLEGAME_HH__


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <list>
#include "PuzzleSprite.hh"

class PuzzleGame
{
  std::string	_picture;
  sf::RenderWindow	&_window;
  bool	_isTarget;

public:
  PuzzleGame(sf::RenderWindow&);
  ~PuzzleGame();
  void	mainGame(sf::Texture&, std::string);
  void	display(std::list<PuzzleSprite*>&, int);
  void	randImg(std::list<PuzzleSprite*>&);
  bool	isPicGood(std::list<PuzzleSprite*>&);
};

#endif
