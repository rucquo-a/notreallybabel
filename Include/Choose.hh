#ifndef	__CHOOSE_HH__
#define	__CHOOSE_HH__

#include	"Button.hh"
#include	"AWin.hh"
#include	<list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	Choose : public AWin
{
  int	_xPlace;
  int	_yPlace;
  typedef AWin  *(*winLoad)(sf::RenderWindow&);

public:
  Choose(sf::RenderWindow&);
  virtual void	updateButton();
  void	createButton(AWin*, std::string&);
  void	loadLib();
  virtual ~Choose();
  virtual void	mainDraw();
};

#endif
