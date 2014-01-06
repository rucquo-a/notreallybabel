#include <iostream>
#include <unistd.h>
#include "AWin.hh"

AWin::AWin(sf::RenderWindow& window) : _window(window)
{
  _button.clear();
}

AWin::~AWin()
{
}

sf::RenderWindow&	AWin::getWindow() const
{
  return (_window);
}

bool	AWin::gestEvent(sf::Event event)
{
  std::list<Button*>::iterator  it;
  std::list<Button*>::iterator  itNew;
  std::list<Button*>::iterator  itEnd;
  std::list<Button*>    but;
  int   mX;
  int   mY;
  int   i;
  bool	newCur = false;

  but = getButton();
  if(event.type == sf::Event::Closed)
    {
      getWindow().close();
      return (false);
    }
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    return (false);
  if (event.type == sf::Event::MouseMoved)
    {
      mX = event.mouseMove.x;
      mY = event.mouseMove.y;
      it = but.begin();
      itEnd = but.end();
      while (it != itEnd && but.size() > 0)
        {
          if ((*it)->isIn(mX, mY) == true)
	    {
	      itNew = it;
	      (*it)->setTarget(true);
	      newCur = true;
	    }
	  it++;
        }
      it = but.begin();
      while (it != itEnd && newCur == true && but.size() > 0)
	{
	  if (it != itNew)
	    (*it)->setTarget(false);
	  it++;
	}
    }
  if (event.type == sf::Event::MouseButtonReleased)
    {
      it = but.begin();
      itEnd = but.end();
      mX = event.mouseButton.x;
      mY = event.mouseButton.y;
      std::cout << mX <<"," << mY << std::endl;
      std::cout << event.type << std::endl;
      while (it != itEnd &&but.size() > 0)
        {
          if ((*it)->isIn(mX, mY) == true)
	    {
	      while (getButton().size() > 0)
		getButton().pop_back();
	      if ((*it) != NULL)
		if ((*it)->getWin() != NULL)
		  {
		    (*it)->getWin()->mainDraw();
		    return (false);
		  }
	    }
	  it++;
        }
    }
  if (event.type == sf::Event::Resized)
    updateButton();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
    upDown();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
    upUp();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
    {    
      launchWindow();
      return (false);
    }  
  getWindow().clear();
  drawContent();
  getWindow().display();
  usleep(1000);
  return (true);
}

void	AWin::launchWindow()
{
  std::list<Button*>	but;
  std::list<Button*>::iterator	it;
  std::list<Button*>::iterator	itEnd;
  bool	on = false;

  but = this->getButton();
  it = but.begin();
  itEnd = but.end();
  while (it != itEnd)
    {
      if ((*it)->getTarget() == true)
	{
	  while (getButton().empty() == false)
	      getButton().pop_back();
	  (*it)->getWin()->mainDraw();
	}
      it++;
    }
}

void	AWin::drawTitle(std::string &title) const
{
  sf::Font      Acent;
  sf::Text	txt;
 
  Acent.loadFromFile("./Ressources/Acens.ttf");
  txt.setFont(Acent);
  txt.setPosition(250, 0);
  txt.setString(title);
  _window.draw(txt);
  _window.display();
}

void	AWin::setType(e_TYPE newType)
{
  _type = newType;
}

e_TYPE	AWin::getType() const
{
  return (_type);
}

void	AWin::upUp()
{
  std::list<Button*>	but;
  std::list<Button*>::iterator	it;
  std::list<Button*>::iterator	itEnd;
  bool	on = false;
  bool	pass = false;

  but = this->getButton();
  it = but.begin();
  itEnd = but.end();
  itEnd--;
  while (on == false)
    {
      if ((*itEnd)->getTarget() == true)
	{
	  on = true;
	  (*itEnd)->setTarget(false);
	  if (it == itEnd)
	    itEnd = but.end();
	  itEnd--;
	  (*itEnd)->setTarget(true);
	}
      else if (itEnd == it)
	{
	  itEnd = but.end();
	  it--;
	}
      else
	itEnd--;
    }
}

void	AWin::upDown()
{
  std::list<Button*>	but;
  std::list<Button*>::iterator	it;
  std::list<Button*>::iterator	itEnd;
  bool	on = false;

  but = this->getButton();
  it = but.begin();
  itEnd = but.end();
  while (it != itEnd && on == false)
    {
      if ((*it)->getTarget() == true)
	{
	  on = true;
	  (*it)->setTarget(false);
	  it++;
	  if (it == itEnd)
	    it = but.begin();
	  (*it)->setTarget(true);
	}
      else
	it++;
    }
}

void	AWin::drawContent()
{
  std::list<Button*>	but;
  std::list<Button*>::iterator	it;
  std::list<Button*>::iterator	itEnd;

  but = this->getButton();
  it = but.begin();
  itEnd = but.end();
  while (it != itEnd)
    {
      (*it)->DrawContent(_window);
      it++;
    }

}

void	AWin::updateButton()
{
  std::list<Button*>::iterator	it;
  std::list<Button*>::iterator	itEnd;
  std::list<Button*>		button;
  int				x;
  int				y;

  button = getButton();
  it = button.begin();
  itEnd = button.end();
  x = _window.getSize().x / 2;
  y = _window.getSize().y / 2;
  while (it != itEnd)
    {
      (*it)->setPosU(x - 150, y - 50);
      (*it)->setPosD(x + 150, y + 50);
      y += 100;
      it++;
    }
  drawContent();
  _window.display();
}

void	AWin::addButton(Button* next)
{
  _button.push_back(next);
}

std::list<Button*>	&AWin::getButton()
{
  return (_button);
}

