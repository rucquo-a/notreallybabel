#ifndef		__TETRISWIN_HH__
 #define	__TETRISWIN_HH__

#include	"AWin.hh"
#include	<SFML/Window.hpp>
#include	<SFML/Graphics.hpp>

class	TetrisWin : public AWin
{
  std::string	_picture;
  sf::Texture	_pic;  
  bool		_good;

public:
  bool	isGood() const;
  TetrisWin(sf::RenderWindow&);
  sf::Texture&	getPic();
  virtual ~TetrisWin();
  virtual void	mainDraw();
};

#endif
