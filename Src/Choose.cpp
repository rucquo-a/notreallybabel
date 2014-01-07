#include <dlfcn.h>
#include <iostream>
#include "Choose.hh"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


Choose::Choose(sf::RenderWindow &window) : AWin(window)
{
  _xPlace = 20;
  _yPlace = 50;
  setType(MENU);
}

Choose::~Choose()
{
}

void	Choose::updateButton()
{
  std::list<Button*>::iterator  it;
  std::list<Button*>::iterator  itEnd;
  std::list<Button*>            button;
  int                           x;
  int                           y;
  int                           x2;
  int                           y2;
  

  _xPlace = 20;
  _yPlace =  50;
  button = getButton();
  it = button.begin();
  itEnd = button.end();
  x = getWindow().getSize().x / 4;
  y = getWindow().getSize().y / 2;
  y -= 100;
  while (it != itEnd)
    {
      (*it)->getPosU(x, y);
      (*it)->getPosD(x2, y2);
      (*it)->setPosD((int)((float)(x2 - x) * 2.4f), (int)((float)(y2 - y) * 2.4f));
      (*it)->setPosU(_xPlace, _yPlace);
      it++;
      _xPlace += x + 50;
      if (_xPlace >= getWindow().getSize().x)
	{
	  _xPlace = 20;
	  _yPlace += y + 150;
      	}
    }
  drawContent();
  getWindow().display();
}

void	Choose::createButton(AWin* window, std::string &name)
{
  Button	*game;
  int	x = getWindow().getSize().x / 2;
  int	y = getWindow().getSize().y / 2;

  name.erase(name.size() - 3, name.size());
  game = new Button(_xPlace, _yPlace, _xPlace + 150, _yPlace + 205, name);
  if (_xPlace == 20 && _yPlace == 50)
    game->setTarget(true);
  window->setType(GAME);
  game->DrawContent(getWindow());
  window->setType(GAME);
  getWindow().display();
  addButton(game);
  game->setWin(window);
  _xPlace += 200;
  if (_xPlace >= 800)
    {
      _xPlace = 20;
      _yPlace += 300;
    }
}

void	Choose::loadLib()
{
  std::list<AWin*>	listWin;
  void*	sym;
  void*	lib;
  winLoad	addr;
  AWin*	window;
  std::string	name;
  std::string	fullName("./Ressources/Game/");
  DIR*	dir;
  struct dirent	*ent;
  struct stat	st;

  _xPlace = 20;
  _yPlace = 50;
  dir = opendir("./Ressources/Game");
  if (dir != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	{
	  name = ent->d_name;
	  fullName = "./Ressources/Game/";
	  fullName += name;
	  if (name[0] != '.' && stat(fullName.c_str(), &st) != -1)
	    if ((st.st_mode & S_IFDIR) == false)
	      if (name.rfind('.') != std::string::npos && name.substr(name.rfind('.')).compare(".so") == 0)
		{
		  lib = dlopen(fullName.c_str(), RTLD_LAZY | RTLD_GLOBAL);
		  if (lib != NULL)
		    if((sym = dlsym(lib, "newWin")) != NULL)
		      {
			addr = reinterpret_cast<winLoad>(sym);
			window = addr(getWindow());
			createButton(window, name);
		      }
		}
	}
    }
}

void	Choose::mainDraw()
{
  std::string	title("Choose your Game!");
  bool	isIn = true;
  sf::Event	event;
  sf::Event	last;

  drawTitle(title);
  getWindow().display();
  loadLib();
  while (isIn == true && getWindow().isOpen() == true)
    {
      getWindow().pollEvent(event);
      if (event.type != 15 && event.type != 10)
        isIn = gestEvent(event);
      if (event.type != 10 && last.type == 10)
	{      
	  isIn = gestEvent(last);
	}
      drawTitle(title);
      getWindow().display();
      last = event;
    }
}
