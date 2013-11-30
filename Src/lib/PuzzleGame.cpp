#include <iostream>
#include "PuzzleGame.hh"

PuzzleGame::PuzzleGame(sf::RenderWindow& window) : AWin(window)
{
  _picture = "./Ressources/Game/Picture/PuzzleGame.jpg";
  _good = false;
  _good = _pic.LoadFromFile(_picture); 
}

PuzzleGame::~PuzzleGame()
{
}

void	PuzzleGame::mainDraw()
{
  std::cout << "in the puzzle Game!" << std::endl;
}

sf::Image&	PuzzleGame::getPic()
{
  return (_pic);
}

bool	PuzzleGame::isGood() const

{
  return (_good);
}

extern "C"
{

  AWin*	newWin(sf::RenderWindow& window)
  {
    return (new PuzzleGame(window));
  }

}
