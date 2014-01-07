#include <list>
#include <unistd.h>
#include <cmath>
#include "Leap.h"
#include "LeapMath.h"
#include "PuzzleGame.hh"
#include "PuzzleSprite.hh"

PuzzleGame::PuzzleGame(sf::RenderWindow& window) : _window(window)
{
  _isTarget = false;
  _diff = false;
}

PuzzleGame::~PuzzleGame()
{
}

void	PuzzleGame::upUp(std::list<PuzzleSprite*>& spr)
{
  std::list<PuzzleSprite*>::iterator	it;
  std::list<PuzzleSprite*>::iterator	itEnd;
  std::list<PuzzleSprite*>::iterator	itNeed;
  int	div;
  bool	nott = true;
  int	i= 0;
  bool	_error = false;
  int	x;
  int	y;
  int	x2;
  int	y2;
  int	idTmp;

  div = powf(spr.size(), 0.5);
  it = spr.begin();
  itEnd = spr.end();
  if (_isTarget == false)
    while (it != itEnd && nott == true)
      {
	if ((*it)->getSelect() == true)
	  {
	    nott = false;
	    (*it)->getId();
	    (*it)->setSelect(false);
	    itNeed = it;
	    i = div;
	    while (i > 0)
	      {
		if (itNeed == spr.begin())
		  itNeed = itEnd;
		itNeed--;
		i--;
	      }
	    (*itNeed)->setSelect(true);
	  }
	it++;
      }
  else
    {
      while (it != itEnd && nott == true)
	{
	  if ((*it)->getSelect() == true)
	    {
	      (*it)->getId();
	      itNeed = it;
	      i = div;
	      while (i > 0)
		{
		  if (itNeed == spr.begin())
		    {
		      _error = true;
		      i = 0;
		    }
		  itNeed--;
		  i--;
		}
	      if (_error == false)
		{
		  if ((*itNeed)->getSprite().getColor() == sf::Color::Black || (*it)->getSprite().getColor() == sf::Color::Black)
		    {
		      x = (*it)->getSprite().getPosition().x;
		      y = (*it)->getSprite().getPosition().y;
		      x2 = (*itNeed)->getSprite().getPosition().x;
		      y2 = (*itNeed)->getSprite().getPosition().y;
		      (*it)->getSprite().setPosition(x2, y2);
		      (*itNeed)->getSprite().setPosition(x, y);
		      idTmp = (*it)->getId();
		      (*it)->setId((*itNeed)->getId());
		      (*itNeed)->setId(idTmp);
		    }
		}
	      nott = false;
	    }
	  it++;
	}
    }
  std::cout << "end" << std::endl;
}

void	PuzzleGame::upLeft(std::list<PuzzleSprite*>& spr)
{
  std::list<PuzzleSprite*>::iterator	it;
  std::list<PuzzleSprite*>::iterator	itEnd;
  std::list<PuzzleSprite*>::iterator	itNeed;
  int	div;
  bool	nott = true;
  int	i= 0;
  bool	_error = false;
  int	x;
  int	y;
  int	x2;
  int	y2;
  int	idTmp;

  div = powf(spr.size(), 0.5);
  it = spr.begin();
  itEnd = spr.end();
  if (_isTarget == false)
    while (it != itEnd && nott == true)
      {
	if ((*it)->getSelect() == true)
	  {
	    nott = false;
	    (*it)->getId();
	    (*it)->setSelect(false);
	    itNeed = it;
	    i = 1;
	    while (i > 0)
	      {
		if (itNeed == spr.begin())
		  itNeed = itEnd;
		itNeed--;
		i--;
	      }
	    (*itNeed)->setSelect(true);
	  }
	it++;
      }
  else
    {
      while (it != itEnd && nott == true)
	{
	  if ((*it)->getSelect() == true)
	    {
	      (*it)->getId();
	      itNeed = it;
	      i = 1;
	      while (i > 0)
		{
		  if (itNeed == spr.begin())
		    {
		      _error = true;
		      i = 0;
		    }
		  itNeed--;
		  i--;
		}
	      if (_error == true)
		std::cout << "error" << std::endl;
	      if (_error == false)
		{
		  if ((*itNeed)->getSprite().getColor() == sf::Color::Black || (*it)->getSprite().getColor() == sf::Color::Black)
		    {
		      x = (*it)->getSprite().getPosition().x;
		      y = (*it)->getSprite().getPosition().y;
		      x2 = (*itNeed)->getSprite().getPosition().x;
		      y2 = (*itNeed)->getSprite().getPosition().y;
		      (*it)->getSprite().setPosition(x2, y2);
		      (*itNeed)->getSprite().setPosition(x, y);
		      idTmp = (*it)->getId();
		      (*it)->setId((*itNeed)->getId());
		      (*itNeed)->setId(idTmp);
		    }
		}
	      nott = false;
	    }
	  it++;
	}
    }

}

void	PuzzleGame::upRight(std::list<PuzzleSprite*>& spr)
{
  std::list<PuzzleSprite*>::iterator	it;
  std::list<PuzzleSprite*>::iterator	itEnd;
  std::list<PuzzleSprite*>::iterator	itNeed;
  int	div;
  bool	nott = true;
  int	i= 0;
  bool	_error = false;
  int	x;
  int	y;
  int	x2;
  int	y2;
  int	idTmp;

  div = powf(spr.size(), 0.5);
  it = spr.begin();
  itEnd = spr.end();
  if (_isTarget == false)
    while (it != itEnd && nott == true)
      {
	if ((*it)->getSelect() == true)
	  {
	    nott = false;
	    (*it)->getId();
	    (*it)->setSelect(false);
	    itNeed = it;
	    i = 1;
	    while (i > 0)
	      {
		if (itNeed == spr.end())
		  itNeed = spr.begin();
		itNeed++;
		if (itNeed ==  spr.end())
		  itNeed = spr.begin();
		i--;
	      }
	    (*itNeed)->setSelect(true);
	  }
	it++;
      }
  else
    {
      while (it != itEnd && nott == true)
	{
	  if ((*it)->getSelect() == true)
	    {
	      (*it)->getId();
	      itNeed = it;
	      i = 1;
	      while (i > 0)
		{
		  itNeed++;
		  if (itNeed == spr.begin())
		    {
		      _error = true;
		      i = 0;
		    }
		  i--;
		}
	      if (_error == false)
		{
		  if ((*itNeed)->getSprite().getColor() == sf::Color::Black || (*it)->getSprite().getColor() == sf::Color::Black)
		    {
		      x = (*it)->getSprite().getPosition().x;
		      y = (*it)->getSprite().getPosition().y;
		      x2 = (*itNeed)->getSprite().getPosition().x;
		      y2 = (*itNeed)->getSprite().getPosition().y;
		      (*it)->getSprite().setPosition(x2, y2);
		      (*itNeed)->getSprite().setPosition(x, y);
		      idTmp = (*it)->getId();
		      (*it)->setId((*itNeed)->getId());
		      (*itNeed)->setId(idTmp);
		    }
		}
	      nott = false;
	    }
	  it++;
	}
    }

}

void	PuzzleGame::upDown(std::list<PuzzleSprite*>& spr)
{
  std::list<PuzzleSprite*>::iterator	it;
  std::list<PuzzleSprite*>::iterator	itEnd;
  std::list<PuzzleSprite*>::iterator	itNeed;
  int	div;
  bool	nott = true;
  int	i= 0;
  bool	_error = false;
  int	x;
  int	y;
  int	x2;
  int	y2;
  int	idTmp;

  div = powf(spr.size(), 0.5);
  it = spr.begin();
  itEnd = spr.end();
  if (_isTarget == false)
    while (it != itEnd && nott == true)
      {
	if ((*it)->getSelect() == true)
	  {
	    nott = false;
	    (*it)->getId();
	    (*it)->setSelect(false);
	    itNeed = it;
	    i = div;
	    while (i > 0)
	      {
		if (itNeed == spr.end())
		  {
		    itNeed = spr.begin();
		  }
		itNeed++;
		i--;
	      }
	    (*itNeed)->setSelect(true);
	  }
	it++;
      }
  else
    {
      while (it != itEnd && nott == true)
	{
	  if ((*it)->getSelect() == true)
	    {
	      (*it)->getId();
	      itNeed = it;
	      i = div;
	      while (i > 0)
		{
		  itNeed++;
		  if (itNeed == spr.begin())
		    {
		      _error = true;
		      i = 0;
		    }
		  i--;
		}
	      if (_error == false)
		{
		  if ((*itNeed)->getSprite().getColor() == sf::Color::Black || (*it)->getSprite().getColor() == sf::Color::Black)
		    {
		      x = (*it)->getSprite().getPosition().x;
		      y = (*it)->getSprite().getPosition().y;
		      x2 = (*itNeed)->getSprite().getPosition().x;
		      y2 = (*itNeed)->getSprite().getPosition().y;
		      (*it)->getSprite().setPosition(x2, y2);
		      (*itNeed)->getSprite().setPosition(x, y);
		      idTmp = (*it)->getId();
		      (*it)->setId((*itNeed)->getId());
		      (*itNeed)->setId(idTmp);
		    }
		}
	      nott = false;
	    }
	  it++;
	}
    }
}

bool	PuzzleGame::gestEvent(sf::Event& event, std::list<PuzzleSprite*>& spr)
{
  std::list<PuzzleSprite*>::iterator	it;
  std::list<PuzzleSprite*>::iterator	itEnd;
  
  it = spr.begin();
  itEnd = spr.end();
  if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
      return (false);
  if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
    {
      if (_isTarget == false)
	_isTarget = true;
      else
	_isTarget = false;
      _diff = true;
    }
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
    {
      _diff = true;
      upUp(spr);
    }
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
    {
      _diff = true;
      upDown(spr);
    }
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
    {
      _diff = true;
      upLeft(spr);
    }
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
    {
      _diff = true;
      upRight(spr);
    }
  return (true);
}

void	PuzzleGame::mainGame(sf::Texture& pic, std::string diff)
{
  int	x = 0;
  int	y = 0;
  int	div;
  int	posX = 0;
  int	posY = 0;
  int	posXPic = 0;
  int	posYPic = 0;
  int	xPic = 0;
  int	yPic = 0;
  std::list<PuzzleSprite*>	spr;
  PuzzleSprite*	next;
  int	id = 0;
  std::list<PuzzleSprite*>::iterator	it;
  std::list<PuzzleSprite*>::iterator	itEnd;
  sf::Event	event;
  sf::Event	last;
  bool	isIn = true;
  int	act = 0;
  int	actIn = 0;
  Leap::Controller	ctrl;
  Leap::Listener                lsnr;
  //Leap::Frame                   fram;
  //Leap::Frame                   lastFram;
  //Leap::Gesture			gest;
  
  ctrl.addListener(lsnr);
  /*  ctrl.enableGesture(Leap::Gesture::TYPE_CIRCLE);
  ctrl.enableGesture(Leap::Gesture::TYPE_KEY_TAP);
  ctrl.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);
  ctrl.enableGesture(Leap::Gesture::TYPE_SWIPE);
  */

  x = 800;
  y = 600;
  xPic = 800;
  yPic = 600;
  xPic = x;
  yPic = y;
  if (diff.compare("Easy") == 0)
    div = 3;
  if (diff.compare("Normal") == 0)
    div = 4;
  if (diff.compare("Hard") == 0)
    div = 5;
  x /= div;
  y /= div;
  xPic /= div;
  yPic /= div;
  while (act < (div * div))
    {
      posXPic = 0;
      posX = 0;
      while (actIn < div)
	{
	  next = new PuzzleSprite(posX, posY);
	  next->setId(id);
	  next->_idPos = id;
	  id++;
	  if (id < div * div)
	    next->getSprite().setTexture(pic);
	  else
	    {
	      next->setSelect(true);
	      next->getSprite().setColor(sf::Color::Black);
	    }	  
	  next->getSprite().setPosition(posX, posY);
	  next->getSprite().setTextureRect(sf::IntRect(posXPic, posYPic, (xPic), ( yPic)));
	  posXPic += xPic;
	  posX +=xPic;
	  spr.push_back(next);
	  actIn++;
	  act++;
	}
      actIn = 0;
      posY += y;
      posXPic = 0;
      posYPic += yPic;
    }
  it = spr.begin();
  itEnd = spr.end();
  _window.clear();
  randImg(spr);
  display(spr, div);
  _window.display();
  it = spr.begin();
  itEnd = spr.end();
  act = 0;
  /*if (ctrl.isConnected())
    {
      std::cout << "coucou" << std::endl;
      //Leap::Frame	frame = ctrl.frame();
      //Leap::Frame	lastFrame = ctrl.frame();
      //Leap::Gesture/*List*//*	gest;
    }
  else
  std::cout << "fuck you!" << std::endl;*/
  //frame = ctrl.frame();
  //lastFrame = frame;
  while(isPicGood(spr) == false && isIn == true)
    {
      /*  if (ctrl.isConnected())
	{
	  frame = ctrl.frame();
	  gest = frame.gestures(lastFrame);
	  // if (gest.isValid())
	  //{
	  for(Leap::GestureList::const_iterator gl = frame.gestures().begin(); gl != frame.gestures().end();)
	    {
	      switch ((*gl).type()) {
	      case Leap::Gesture::TYPE_CIRCLE:
		std::cout << "circle" << std::endl;
		break;
	      case Leap::Gesture::TYPE_KEY_TAP:
		std::cout << "tap" << std::endl;
		break;
	      case Leap::Gesture::TYPE_SCREEN_TAP:
		std::cout << "type" << std::endl;
		break;
	      case Leap::Gesture::TYPE_SWIPE:
		std::cout << "swap" << std::endl;
		break;
	      default:
		std::cout << "defautl" << std::endl;
		break;
	      }
	    }
	  //}
	  }*/
      _window.pollEvent(event);
      _diff = false;
      if(last.key.code != event.key.code)
	{
	  if (event.type != 15 && event.type != 10)
	    isIn = gestEvent(event, spr);
	  if (event.type != 10 && last.type == 10)
	    {
	      isIn = gestEvent(last, spr);
	    }
	}
      if (event.type == sf::Event::Closed)
	{
	  _window.close();
	  isIn = false;
	}
      if (_diff == true)
	{
	  _window.clear();
	  display(spr, div);
	  _window.display();
	}
      last = event;
      usleep(15000);
      //lastFrame = frame;
}
_window.clear();
  _window.display();
}

void	PuzzleGame::colorRect(sf::Color col, int xPic, int posXPic, int posYPic, int yPic)
{
  sf::RectangleShape	*line;

  line = new sf::RectangleShape(sf::Vector2f((float)xPic, 5.0f));
  line->setPosition((float)posXPic, (float)posYPic);
  line->setFillColor(col);
  _window.draw(*line);
  line = new sf::RectangleShape(sf::Vector2f((float)yPic, 5.0f));
  line->setPosition((float)posXPic, (float)posYPic);
  line->setFillColor(col);
  line->setRotation(90.0f);
  _window.draw(*line);
  line = new sf::RectangleShape(sf::Vector2f((float)xPic, 5.0f));
  line->setPosition((float)posXPic, (float)posYPic + (float)yPic - (float)5);
  line->setFillColor(col);
  _window.draw(*line);
  line = new sf::RectangleShape(sf::Vector2f((float)yPic, 5.0f));
  line->setPosition((float)posXPic + (float)xPic, (float)posYPic);
  line->setRotation(90.0f);
  line->setFillColor(col);
  _window.draw(*line);
}

void	PuzzleGame::display(std::list<PuzzleSprite*>& spr, int div)
{

  int	x = 800;
  int	y = 600;
  int	posX = 0;
  int	posY = 0;
  int	posXPic = 0;
  int	posYPic = 0;
  int	xPic = 800;
  int	yPic = 600;
  std::list<PuzzleSprite*>::iterator	it;
  std::list<PuzzleSprite*>::iterator	itEnd;
  int					need = 0;
  int					act = 0;
  

  x /= div;
  y /= div;
  xPic /= div;
  yPic /= div;
  it = spr.begin();
  need = div * div;
  while (posYPic <= (yPic * div) && need > act)
    {
      posXPic = 0;
      posX = 0;
      while (posXPic < (xPic * div))
	{
	  _window.draw((*it)->getSprite());
	  act++;
	  posXPic += xPic;
	  posX +=xPic;
	  it++;
	}
      posY += y;
      posYPic += yPic;
    }
  posXPic = 0;
  posYPic = 0;
  posX = 0;
  posY = 0;
  it = spr.begin();
  act = 0;
  while (posYPic <= (yPic * div) && need > act)
    {
      posXPic = 0;
      posX = 0;
      while (posXPic < (xPic * div))
	{
	  if ((*it)->getSelect() == true)
	    {
	      if (_isTarget == true)
		colorRect(sf::Color::Yellow, xPic, posXPic, posYPic, yPic);
	      else
		colorRect(sf::Color::White, xPic, posXPic, posYPic, yPic);
	    }
	  act++;
	  posXPic += xPic;
	  posX +=xPic;
	  it++;
	}
      posY += y;
      posYPic += yPic;
    }
  spr.sort(compare_id);
}

bool	compare_id(const PuzzleSprite* first, const PuzzleSprite* second)
{
  if (first->getId() > second->getId())
    return (false);
  else
    return (true);
}

void	PuzzleGame::randImg(std::list<PuzzleSprite*>& spr)
{
  int	x;
  int	y;
  int	x2;
  int	y2;
  int	bcl = 0;
  int	rd = 0;
  int	rd2 = 0;
  std::list<PuzzleSprite*>::iterator	it;
  std::list<PuzzleSprite*>::iterator	it2;
  int	need;
  int	div;
  PuzzleSprite*	tmp;
  int	idTmp;
  bool	in = false;

  srand(time(NULL));
  div = spr.size();
  div = powf((float)(div), 0.5);
  need = spr.size() * 100;
  it = spr.end();
  it--;
  while (bcl < need)
    {
      rd = rand() % 4;
      if (rd == 0)
	{
	}
      if (rd == 1)
	{
	}
      if (rd == 2)
	{
	}
      if (rd == 3)
	{
	}
      
      
      
      it = spr.begin();
      it2 = spr.begin();
      while (in == false)
	{
	  rd = rand() % (div * div);
	  rd2 = rand() % (div * div);
	  if (rd < (div*div) && rd2 < (div*div))
	    in = true;
	}
      in = false;
      std::advance(it, rd);
      std::advance(it2, rd2);
      x = (*it)->getSprite().getPosition().x;
      y = (*it)->getSprite().getPosition().y;
      x2 = (*it2)->getSprite().getPosition().x;
      y2 = (*it2)->getSprite().getPosition().y;
      (*it)->getSprite().setPosition(x2, y2);
      (*it2)->getSprite().setPosition(x, y);
      idTmp = (*it)->getId();
      (*it)->setId((*it2)->getId());      
      (*it2)->setId(idTmp);
      bcl++;
    }
  it = spr.begin();
  it2 = spr.end();
  spr.sort(compare_id);
}

bool	PuzzleGame::isPicGood(std::list<PuzzleSprite*>& spr)
{
  std::list<PuzzleSprite*>::iterator	it = spr.begin();
  std::list<PuzzleSprite*>::iterator	itEnd = spr.end();
  int		id;

  id = -1;
  while(it != itEnd && (id + 1) == (*it)->_idPos)
    {
      _window.draw((*it)->getSprite());
      it++;
    }
  _window.display();
  if (it == itEnd)
    return (true);
  return (false);
}
