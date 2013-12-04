#ifndef	__BUTTON_HH__
#define	__BUTTON_HH__

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "AWin.hh"

class	AWin;

class Button
{
  std::string	_val;
  bool		_isTarget;
  int		_posXu;
  int		_posYu;
  int		_initX;
  int		_initY;
  int		_posXd;
  int		_posYd;
  AWin		*_currentWindow;

public:
  Button();
  Button(int, int, int, int, std::string);
  ~Button();
  std::string	getContent() const;
  void	setTarget(bool);
  bool	getTarget() const;
  void	setWin(AWin*);
  void	getPosU(int&, int&) const;
  void	getPosD(int&, int&) const;
  void	setPosU(int, int);
  void	setPosD(int, int);
  bool	isIn(int, int) const;
  AWin*	getWin() const;
  void	DrawContent(sf::RenderWindow&) const;
};

#endif
