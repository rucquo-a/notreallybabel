#ifndef	__WIN_HH__
#define	__WIN_HH__

#include	"Button.hh"
#include	"AWin.hh"
#include	<list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	Win : public AWin
{
public:
  Win(sf::RenderWindow&);
  virtual ~Win();
  virtual void	mainDraw();
};

#endif
