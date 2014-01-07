#include <iostream>
#include "TetrisMap.hh"

Map::Map()
{
  reset();
}
 
void Map::reset()
{
  for(int y=0;y < HEIGHT;y++)
    for(int x=0;x < WIDTH;x++)
      _data[y][x] = 0;
}
 
bool Map::isCollision(Part part)
{
  for(int y=0;y < 4;y++)
    for(int x=0;x < 4;x++)
      if((part.getPosY() + y >= 0) && ((_data[part.getPosY() + y + 1][part.getPosX() + x] && part.getElement(x, y)) ||
					(part.getElement(x, y) && part.getPosY() + y >= HEIGHT - 1)))
	return true;
  
  return false;
}
 
void Map::addPart(Part part)
{
  for(int y=0;y < 4;y++)
    for(int x=0;x < 4;x++)
      if(part.getElement(x, y))
	_data[part.getPosY() + y][part.getPosX() + x] = 1;
}

void Map::applyGravity(int h)
{
  for(int y=h;y > -1;y--)
    for(int x=0;x < WIDTH;x++)
      if(y < HEIGHT - 1 && _data[y+1][x] == 0 && _data[y][x])
	{
	  _data[y][x] = 0;
	  _data[y+1][x] = 1;
	}
}
 
void Map::destroyLines()
{
  for(int y=0;y < HEIGHT;y++)
    {
      bool good = true;
      for(int x=0;x < WIDTH;x++)
	if(!_data[y][x])
	  {
	    good = false;
	    break;
	  }
      if(good)
	{
	  for(int x=0;x < WIDTH;x++)
	    _data[y][x] = 0;
	  applyGravity(y);
	  y=0;
	}
    }
}
 
bool Map::isFull()
{
  for(int x=0;x < WIDTH;x++)
    if(_data[0][x])
      return true;
  return false;
}
 
void Map::draw(sf::RenderWindow & window)
{
  for(int i=0;i < HEIGHT;i++)
    for(int m=0;m < WIDTH;m++)
      if(_data[i][m])
	drawQuad(window, m * SIZE, i * SIZE, sf::Color::White);
}
