#include <iostream>
#include "Win.hh"

Win::Win(sf::RenderWindow& window) : AWin(window)
{
}

Win::~Win()
{
}

void	Win::mainDraw()
{
  std::cout << "in NExt!" << std::endl;
}
