#ifndef	__LEAVE_HH__
#define	__LEAVE_HH__

#include	"Button.hh"
#include	"AWin.hh"
#include	<list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	Leave : public AWin
{
public:
  Leave(sf::RenderWindow&);
  virtual ~Leave();
  virtual void	mainDraw();
};

#endif
