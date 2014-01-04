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
  if(event.Type == sf::Event::Closed)
    {
      getWindow().Close();
      return (false);
    }
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape)
    return (false);
  if (event.Type == sf::Event::MouseMoved)
    {
      mX = event.MouseMove.X;
      mY = event.MouseMove.Y;
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
  if (event.Type == sf::Event::MouseButtonReleased)
    {
      it = but.begin();
      itEnd = but.end();
      mX = event.MouseButton.X;
      mY = event.MouseButton.Y;
      std::cout << mX <<"," << mY << std::endl;
      std::cout << event.Type << std::endl;
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
  if (event.Type == sf::Event::Resized)
    updateButton();
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Down)
    upDown();
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Up)
    upUp();
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Return)
    {    
      launchWindow();
      return (false);
    }  
  // getWindow().Clear();
  //drawContent();
  //getWindow().Display();
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
  sf::String	txt;
 
  Acent.LoadFromFile("./Ressources/Acens.ttf");
  txt.SetFont(Acent);
  txt.SetPosition(250, 0);
  txt.SetText(title);
  _window.Draw(txt);
  //_window.Display();
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
  x = _window.GetWidth() / 2;
  y = _window.GetHeight() / 2;
  while (it != itEnd)
    {
      (*it)->setPosU(x - 150, y - 50);
      (*it)->setPosD(x + 150, y + 50);
      y += 100;
      it++;
    }
  drawContent();
  _window.Display();
}

void	AWin::addButton(Button* next)
{
  _button.push_back(next);
}

std::list<Button*>	&AWin::getButton()
{
  return (_button);
}

