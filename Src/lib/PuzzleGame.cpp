#include <list>
#include <unistd.h>
#include <cmath>
#include "PuzzleGame.hh"
#include "PuzzleSprite.hh"

PuzzleGame::PuzzleGame(sf::RenderWindow& window) : _window(window)
{
}

PuzzleGame::~PuzzleGame()
{
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
  while (posYPic <= (yPic * div))
    {
      posXPic = 0;
      posX = 0;
      while (posXPic < (xPic * div))
	{
	  next = new PuzzleSprite(posX, posY);
	  next->setId(id);
	  id++;
	  if (id < div * div)
	    next->getSprite().setTexture(pic);
	  else
	    next->getSprite().setColor(sf::Color::Black);
	  next->getSprite().setPosition(posX, posY);
	  next->getSprite().setTextureRect(sf::IntRect(posXPic, posYPic, (xPic), ( yPic)));
	  posXPic += xPic;
	  posX +=xPic;
	  spr.push_back(next);
	}
      posY += y;
      posXPic = 0;
      posYPic += yPic;
    }
  it = spr.begin();
  itEnd = spr.end();
  _window.clear();
  _window.clear();
  randImg(spr);
  display(spr, div);
  _window.display();
  sleep(50);
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
  _window.clear();
  need = div * div;
  while (posYPic <= (yPic * div) && need > act)
    {
      posXPic = 0;
      posX = 0;
      while (posXPic < (xPic * div))
	{
	  if ((*it)->getSelect() == true)
	    {
	      if (_isTarget == true)
		;//_window.draw(sf::RectangleShape(posXPic, posYPic, (posXPic + xPic), (posYPic + yPic), sf::Color(0, 255, 255, 1), 3));
	      else
		{
		  //  _window.draw(sf::Shape::rectangle(posXPic, posYPic, posXPic + xPic, posYPic + yPic, sf::Color(255, 0, 255, 10), 10));
		}
	    }
	  //_window.Draw(sf::Shape::Rectangle(posXPic, posYPic, posXPic + xPic, posYPic + yPic, sf::Color(255, 255, 0, 255), 10));
	  _window.draw((*it)->getSprite());
	  _window.display();
	  //sleep(1);
	  act++;
	  posXPic += xPic;
	  posX +=xPic;
	  it++;
	}
      posY += y;
      posYPic += yPic;
    }
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
  std::cout << "div :" << div << std::endl;
  while (bcl < need)
    {
      it = spr.begin();
      it2 = spr.begin();
      while (in == false)
	{
	  std::cout << "rd:" << rd << ", rd 2 " << rd2 << std::endl;
	  rd = rand() % (div * div);
	  rd2 = rand() % (div * div);
	  if (rd < (div*div) && rd2 < (div*div))
	    in = true;
	}
      std::cout << "out" << std::endl;
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
  (*it)->setSelect(true);
}

bool	PuzzleGame::isPicGood(std::list<PuzzleSprite*>& spr)
{
  std::list<PuzzleSprite*>::iterator	it = spr.begin();
  std::list<PuzzleSprite*>::iterator	itEnd = spr.end();
  int		id;

  id = -1;
  while(it != itEnd && (id + 1) == (*it)->getId())
    {
      _window.draw((*it)->getSprite());
      it++;
    }
  _window.display();
  sleep(5);
}
