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
  std::list<PuzzleSprite*>	spr;
  PuzzleSprite*	next;
  int	id = 0;
  std::list<PuzzleSprite*>::iterator	it;
  std::list<PuzzleSprite*>::iterator	itEnd;


  x = pic.GetWidth();
  y = pic.GetHeight();
  if (diff.compare("Easy") == 0)
    div = 3;
  if (diff.compare("Normal") == 0)
    div = 4;
  if (diff.compare("Hard") == 0)
    div = 5;
  x /= div;
  y /= div;
  while (posY < (y * div))
    {
      posX = 0;
      while (posX < (x * div))
	{
	  next = new PuzzleSprite(posX, posY);
	  next->setId(id);
	  id++;
	  next->getSprite().SetImage(pic);
	  next->getSprite().SetPosition(posX, posY);
	  next->getSprite().SetSubRect(sf::IntRect(posX, posY, (posX + x), (posY + y)));
	  posX += x;
	  spr.push_back(next);
	}
      posY += y;
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
