#ifndef __TETRISOVER_HH__
#define __TETRISOVER_HH__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>

const int WIDTH = 12;
const int HEIGHT = 20;
const int SIZE = 40;

extern const sf::Color colors[7];
  
enum ShapeIndexes { I = 0, O = 4, S = 8, Z = 12, T = 16, L = 20, J = 24 };

extern const bool SHAPES[][4][4];
  
void drawQuad(sf::RenderWindow &, float , float, sf::Color); 

#endif
