#ifndef __TETRISPART_HH__
#define __TETRISPART_HH__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "TetrisOver.hh"

class Part
{
 private:
  int _shapeIndex;
  int _data[4][4];
  int _posX;
  int _posY;
  int color;

  void	fillData();

 public:
  Part();
  void generate();
  void move(int, int);
  void rotate();
  bool isValid(int, int);
  void draw(sf::RenderWindow &);
  int getPosX();
  int getPosY();
  int getElement(int, int);
};

#endif
