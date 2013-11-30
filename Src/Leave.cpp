#include <iostream>
#include "Leave.hh"

Leave::Leave(sf::RenderWindow& window) : AWin(window) 
{
  setType(MENU);
}

Leave::~Leave()
{
}

void	Leave::mainDraw()
{
  getWindow().Clear();
  getWindow().Close();
}
