#include	<SFML/Window.hpp>
#include	<SFML/Graphics.hpp>
#include	<list>
#include	<unistd.h>
#include	<iostream>
#include	<string>
#include	"Choose.hh"
#include	"Leave.hh"
#include	"Win.hh"


void	initMenu(sf::RenderWindow& win, AWin &current)
{
  Button	*chooseGame;
  Button	*leaveGame;
  
  int	x2 = win.getSize().x / 2;
  int	y2 = win.getSize().y / 2;
  chooseGame = new Button(x2 - 150, y2 - 50, x2 + 150, y2 + 50, "Choose Game");
  chooseGame->setWin(new Choose(win));
  chooseGame->setTarget(true);
  chooseGame->DrawContent(win);
  current.addButton(chooseGame);
  leaveGame = new Button(x2 - 150, y2 + 100, x2 + 150, y2 + 200, "Leave");
  leaveGame->DrawContent(win);
  leaveGame->setWin(new Leave(win));
  current.addButton(leaveGame);
}

void	gestEvent(sf::Event event, sf::RenderWindow& window, AWin &currentWin)
{
  std::list<Button*>::iterator	it;
  std::list<Button*>::iterator	itEnd;
  std::list<Button*>	but;
  int	mX;
  int	mY;
  int	i;

  if(event.type == sf::Event::Closed)
    window.close();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    window.close();
  if (event.type == sf::Event::MouseButtonReleased)
    {

      but = currentWin.getButton();
      it = but.begin();
      itEnd = but.end();
      mX = event.mouseButton.x;
      mY = event.mouseButton.y;
      std::cout << mX <<"," << mY << std::endl;
      while (it != itEnd)
	{
	  if ((*it)->isIn(mX, mY) == true)
	    (*it)->getWin()->mainDraw();
	  it++;
	}
    }
  if (event.type == sf::Event::Resized)
    currentWin.updateButton();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
    currentWin.upDown();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
    currentWin.upUp();
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
    currentWin.launchWindow();
  window.clear();
  currentWin.drawContent();
  window.display();
}

int	main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600, 32), "ArcadeLeap");
  sf::Event	event;
  Win		currentWin(window);


  currentWin.setType(MENU);
  initMenu(window, currentWin);
  window.display();
  while (window.isOpen())
    {
      window.pollEvent(event);
      gestEvent(event, window, currentWin); 
      usleep(40000);
      window.clear();
      if(currentWin.getButton().size() == 0)
	initMenu(window, currentWin);	
      currentWin.drawContent();
      window.display();
    }
  return (0);
}
