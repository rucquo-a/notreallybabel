#ifndef	__PuzzleGame_HH__
#define	__PuzzleGame_HH__

#include	"Button.hh"
#include	"AWin.hh"
#include	<list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	PuzzleGame : public AWin
{
  std::string	_picture;
  sf::Image	_pic;
  bool		_good;

public:
  sf::Image&	getPic();
  bool	isGood() const;
  PuzzleGame(sf::RenderWindow&);
  virtual ~PuzzleGame();
  virtual void	mainDraw();
};

#endif
