#ifndef __PUZZLEGAME_HH__
#define __PUZZLEGAME_HH__


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <list>
#include "PuzzleSprite.hh"

bool    compare_id(const PuzzleSprite*, const PuzzleSprite*);

class PuzzleGame
{
  std::string	_picture;
  sf::RenderWindow	&_window;
  bool	_isTarget;
  bool	_diff;

public:
  PuzzleGame(sf::RenderWindow&);
  ~PuzzleGame();
  bool	gestEvent(sf::Event&, std::list<PuzzleSprite*>&);
  void	upUp( std::list<PuzzleSprite*>&);
  void	upRight( std::list<PuzzleSprite*>&);
  void	upLeft( std::list<PuzzleSprite*>&);
  void	upDown( std::list<PuzzleSprite*>&);
  void	colorRect(sf::Color, int, int, int, int);
  void	mainGame(sf::Texture&, std::string);
  void	display(std::list<PuzzleSprite*>&, int);
  void	randImg(std::list<PuzzleSprite*>&);
  bool	isPicGood(std::list<PuzzleSprite*>&);
};

#endif
