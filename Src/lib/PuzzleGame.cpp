#include <list>
#include <unistd.h>
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


  x = _window.getSize().x;
  y = _window.getSize().y;
  xPic = pic.getSize().x;
  yPic = pic.getSize().y;
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
	  next->getSprite().setTexture(pic);
	  next->getSprite().setPosition(posX, posY);
	  //next->getSprite().Resize(800, 600);
	  std::cout << "posX : " << posX << ", posY : " << posY << std::endl;
	  next->getSprite().setTextureRect(sf::IntRect(posXPic, posYPic, (posXPic + xPic), (posYPic + yPic)));
	  posXPic += xPic;
	  posX +=xPic;
	  spr.push_back(next);
	}
      posY += y;
      posYPic += yPic;
    }
  it = spr.begin();
  itEnd = spr.end();
<<<<<<< HEAD
  std::cout << "act : " << act << std::endl;
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
  _window.Clear();
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
		_window.Draw(sf::Shape::Rectangle(posXPic, posYPic, (posXPic + xPic), (posYPic + yPic), sf::Color(0, 255, 255, 1), 3));
	      else
		{
		  _window.Draw(sf::Shape::Rectangle(posXPic, posYPic, posXPic + xPic, posYPic + yPic, sf::Color(255, 0, 255, 10), 10));
		}
	    }
	  //_window.Draw(sf::Shape::Rectangle(posXPic, posYPic, posXPic + xPic, posYPic + yPic, sf::Color(255, 255, 0, 255), 10));
	  _window.Draw((*it)->getSprite());
	  _window.Display();
	  sleep(1);
	  act++;
	  posXPic += xPic;
	  posX +=xPic;
	  it++;
	}
      posY += y;
      posYPic += yPic;
    }
  _window.Display();
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

  srand(time(NULL));
  
  div = spr.size();
  div = powf((float)(div), 0.5);
  need = spr.size() * 100;
  while (bcl < need)
    {
      it = spr.begin();
      it2 = spr.begin();
      rd = rand() % spr.size();
      rd2 = rand() % spr.size();
      std::advance(it, rd);
      std::advance(it2, rd2);
      x = (*it)->getSprite().GetPosition().x;
      y = (*it)->getSprite().GetPosition().y;
      x2 = (*it2)->getSprite().GetPosition().x;
      y2 = (*it2)->getSprite().GetPosition().y;
      (*it)->getSprite().SetPosition(x2, y2);
      (*it2)->getSprite().SetPosition(x, y);
      tmp = (*it);      
      (*it) = (*it2);
      (*it2) = tmp;
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
