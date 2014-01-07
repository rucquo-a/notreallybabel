#include <list>
#include <unistd.h>
#include "TetrisPart.hh"

Part::Part()
{
  _posX = 2;
  _posY = -4;
  generate();
}
 
void Part::fillData()
{
  for(int i=0;i < 4;i++)
    for(int m=0;m < 4;m++)
      _data[i][m] = SHAPES[_shapeIndex][i][m];
}


void Part::generate()
{
  int g = (rand() % 7) * 4;
  _shapeIndex = (ShapeIndexes)g;
  color = g / 4;
  fillData();
}

void Part::move(int x, int y)
{
  if(isValid(x, y))
    {
      _posX += x;
      _posY += y;
    }
  
}
 
void Part::rotate()
{
  int coIndex = _shapeIndex;
  _shapeIndex = ((_shapeIndex + 1) % 4 == 0 ? _shapeIndex - 3 : _shapeIndex + 1);
  fillData();
  if(!isValid(0, 0))
    {
      _shapeIndex = coIndex;
      fillData();
    }
}
 
bool Part::isValid(int xOffset = 0, int yOffset = 0)
{
  for(int y=0;y < 4;y++)
    for(int x=0;x < 4;x++)
      if((_data[y][x] && (_posX + x + xOffset >= WIDTH || _posX + xOffset < 0)) || (_data[y][x] && (_posY + y + yOffset > HEIGHT)) )
	{
	  return false;
	}
  
  return true;
}

void Part::draw(sf::RenderWindow & window)
{
  for(int i=0;i < 4;i++)
    for(int m=0;m < 4;m++)
      if(_data[i][m])
	{
	  drawQuad(window, (m + _posX) * SIZE, (i + _posY) * SIZE, colors[color]);
	}
}

int Part::getPosX()
{
  return (_posX);
}

int Part::getPosY()
{
  return (_posY);
}

int Part::getElement(int x, int y)
{
  return (_data[y][x]);
}
