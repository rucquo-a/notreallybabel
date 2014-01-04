#include "Button.hh"
#include <iostream>

Button::Button()
{
}

Button::Button(int posXu, int posYu, int posXd, int posYd, std::string content)
{
  _posXu = posXu;
  _posYu = posYu;
  _posXd = posXd;
  _posYd = posYd;
  _val = content;
  _currentWindow = NULL;
  _initX = posXu;
  _initY = posYu;
  _isTarget = false;
}

Button::~Button()
{
}


void	Button::setTarget(bool tr)
{
  _isTarget = tr;
}

bool	Button::getTarget() const
{
  return (_isTarget);
}

void	Button::setWin(AWin* newWin)
{
  _currentWindow = newWin;
}

void	Button::getPosU(int &retX, int &retY) const
{
  retX = _posXu;
  retY = _posYu;
}

void	Button::getPosD(int &retX, int &retY) const
{
  retX = _posXd;
  retY = _posYd;
}

void	Button::setPosU(int x, int y)
{
  _posXu = x;
  _posYu = y;
}

void	Button::setPosD(int x, int y)
{
  _posXd = x;
  _posYd = y;
}

bool	Button::isIn(int x, int y) const
{
  if (x >= _posXu && x <= _posXd)
    if (y >= _posYu && y <= _posYd)
      return (true);
  return (false);
}

std::string	Button::getContent() const
{
  return (_val);
}

AWin*	Button::getWin() const
{
  return (_currentWindow);
}

void	Button::DrawContent(sf::RenderWindow &in) const
{
  sf::String	txt;
  sf::Font	Acent;
  sf::Sprite	pic;
  int	x;
  int	y;
  int	x2;
  int	y2;

  getPosU(x, y);
  getPosD(x2, y2);
  x2 = in.GetWidth() / 4;
  //x2 -= 100;
  Acent.LoadFromFile("./Ressources/Acens.ttf");
  if (_isTarget == true)
    txt.SetColor(sf::Color(205, 225, 0));
  txt.SetFont(Acent);
  txt.SetText(this->getContent());
  txt.SetPosition(_initX, _initY);
  in.Draw(txt);
  if (this->getWin() != NULL)
    if (this->getWin()->getType() == GAME)
      {
	if (this->getWin()->isGood() == true)
	  {
	    pic.SetPosition(_initX, _initY + 50);
0	    pic.SetImage(this->getWin()->getPic());
	    pic.Resize(150, 150);
	    in.Draw(pic);
	  }
      }
}
