#include	<SFML/Window.hpp>
#include	<SFML/Graphics.hpp>
#include	<list>
#include	"Choose.hh"
#include	"Leave.hh"
#include	"Win.hh"
#include	<iostream>
#include	<string>

void	initMenu(sf::RenderWindow& win, AWin &current)
{
  Button	*chooseGame;
  Button	*leaveGame;
  
  int	x2 = win.GetWidth() / 2;
  int	y2 = win.GetHeight() / 2;
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

  if(event.Type == sf::Event::Closed)
    window.Close();
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape)
    window.Close();
  if (event.Type == sf::Event::MouseButtonReleased)
    {

      but = currentWin.getButton();
      it = but.begin();
      itEnd = but.end();
      mX = event.MouseButton.X;
      mY = event.MouseButton.Y;
      std::cout << mX <<"," << mY << std::endl;
      while (it != itEnd)
	{
	  if ((*it)->isIn(mX, mY) == true)
	    (*it)->getWin()->mainDraw();
	  it++;
	}
    }
  if (event.Type == sf::Event::Resized)
    currentWin.updateButton();
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Down)
    currentWin.upDown();
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Up)
    currentWin.upUp();
  if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Return)
    currentWin.launchWindow();
  window.Clear();
  currentWin.drawContent();
  window.Display();
}

int	main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600, 32), "ArcadeLeap");
  sf::Event	event;
  Win		currentWin(window);


  currentWin.setType(MENU);
  initMenu(window, currentWin);
  window.Display();
  while (window.IsOpened())
    {
      window.GetEvent(event);
      gestEvent(event, window, currentWin); 
      usleep(40000);
      window.Clear();
      if(currentWin.getButton().size() == 0)
	initMenu(window, currentWin);	
      currentWin.drawContent();
      window.Display();
    }
  return (0);
}
