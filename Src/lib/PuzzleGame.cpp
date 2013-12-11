#include <list>
#include "PuzzleGame.hh"
#include "PuzzleSprite.hh"

PuzzleGame::PuzzleGame(sf::RenderWindow& window) : _window(window)
{
}

PuzzleGame::~PuzzleGame()
{
}

void	PuzzleGame::mainGame(sf::Image& pic, std::string diff)
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


  x = _window.GetWidth();
  y = _window.GetHeight();
  xPic = pic.GetWidth();
  yPic = pic.GetHeight();
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
	  next->getSprite().SetImage(pic);
	  next->getSprite().SetPosition(posX, posY);
	  //next->getSprite().Resize(800, 600);
	  std::cout << "posX : " << posX << ", posY : " << posY << std::endl;
	  next->getSprite().SetSubRect(sf::IntRect(posXPic, posYPic, (posXPic + xPic), (posYPic + yPic)));
	  posXPic += xPic;
	  posX +=xPic;
	  spr.push_back(next);
	}
      posY += y;
      posYPic += yPic;
    }
  it = spr.begin();
  itEnd = spr.end();
  _window.Clear();
  while (it != itEnd)
    {
      _window.Draw((*it)->getSprite());
      it++;
    }
  _window.Display();
  sleep(5);
}
