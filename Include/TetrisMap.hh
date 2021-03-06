#ifndef __TETRISMAP_HH__
#define __TETRISMAP_HH__


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include "TetrisOver.hh"
#include "TetrisPart.hh"

//class Part;

class Map
{
private:
  int _data[20][12];

public:
  Map();
  void reset();
  bool isCollision(Part);
  void addPart(Part);
  void applyGravity(int);
  void destroyLines();
  bool isFull();
  void draw(sf::RenderWindow &);
};

#endif
