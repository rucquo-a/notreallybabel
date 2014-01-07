#include <list>
#include <unistd.h>
#include "TetrisGame.hh"


TetrisGame::TetrisGame(sf::RenderWindow& window) : _window(window)
{
}

TetrisGame::~TetrisGame()
{
}

void	TetrisGame::mainGame()
{
  srand(time(0));
  _window.setView(sf::View(sf::FloatRect(0, 0, 12 * SIZE, 20 * SIZE)));
  _window.setSize(sf::Vector2u(12 * SIZE, 20 *SIZE));
  _window.setFramerateLimit(30);
  
  Map map;
  Part part;
  int tick = 0;
  sf::Font Acent;
  sf::Text text;
  
  Acent.loadFromFile("./Ressources/Acens.ttf");
  text.setFont(Acent);
  text.setString("Game Over");
  text.setPosition(115,400);
  text.setCharacterSize(40);
  text.setColor(sf::Color::Red);
  bool gameOver = false;
  while(_window.isOpen())
    {
      sf::Event event;
      while(_window.pollEvent(event))
        {
	  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	    {
	      _window.setView(sf::View(sf::FloatRect(0, 0, 800, 600)));
	      _window.setSize(sf::Vector2u(800, 600));
	      return;
	    }
	  if (event.type == sf::Event::Closed)
	    _window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
	      {
                Part p = part;
                part.move(1, 0);
                if(map.isCollision(part))
		  part = p;
	      }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
	      {
                Part p = part;
                part.move(-1, 0);
                if(map.isCollision(part))
		  part = p;
	      }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
	      {
                while(!map.isCollision(part))
                {
		  part.move(0, 1);
                }
	      }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            {
	      Part p = part;
	      part.rotate();
	      if(map.isCollision(part))
		part = p;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
	      gameOver = false;
        }
      _window.clear();
      
      if (gameOver)
        {
	  _window.draw(text);
	  _window.display();
	  continue;
        }
      
      if (tick % 30 == 0)
	part.move(0, 1);
 
      if(map.isCollision(part))
	{
	  map.addPart(part);
	  map.destroyLines();
            part = Part();
	}
      map.draw(_window);
      part.draw(_window);
      if (tick <= 30)
	tick++;
      else
	tick = 1;	
      if (map.isFull())
	{
	  _window.draw(text);
	  map.reset();
	  gameOver = true;
	}
      _window.display();	
    }
}
