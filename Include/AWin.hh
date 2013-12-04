#ifndef	__AWIN_HH__
#define	__AWIN_HH__

#include	"Button.hh"
#include	<list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Button;

enum	e_TYPE
  {
    MENU,
    GAME
  };

class	AWin
{
  std::list<Button*>	_button;
  e_TYPE	_type;
  sf::RenderWindow	&_window;

public:
  AWin(sf::RenderWindow&);
  virtual ~AWin();

  virtual void			setType(e_TYPE);
  virtual bool			isGood()const {return (false);};
  virtual sf::Image&		getPic() {};
  virtual e_TYPE		getType() const;
  virtual sf::RenderWindow&	getWindow() const;
  virtual void			drawTitle(std::string&) const;
  virtual void			launchWindow();
  virtual void			upDown();
  virtual void			upUp();
  virtual void			mainDraw() = 0;
  virtual void			drawContent();
  virtual std::list<Button*>&	getButton();
  virtual void			addButton(Button*);
  virtual bool			gestEvent(sf::Event);
  virtual void			updateButton();
};

#endif
