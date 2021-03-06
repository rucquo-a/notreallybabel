#include <iostream>
#include <unistd.h>
#include "TetrisGame.hh"
#include "TetrisWin.hh"

TetrisWin::TetrisWin(sf::RenderWindow& window) : AWin(window)
{
  _picture = "./Ressources/Game/Picture/TetrisGame.jpg";
  _good = false;
  _good = _pic.loadFromFile(_picture);
}

TetrisWin::~TetrisWin()
{
}

void	TetrisWin::mainDraw()
{
  TetrisGame	*game;
 
  getWindow().clear();
  game = new TetrisGame(getWindow());
  game->mainGame();
}

sf::Texture&	TetrisWin::getPic()
{
  return (_pic);
}

bool	TetrisWin::isGood() const
{
  return (_good);
}

extern "C"
{

  AWin*	newWin(sf::RenderWindow& window)
  {
    return (new TetrisWin(window));
  }

}
