#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "PuzzleGame.hh"
#include "PuzzleWin.hh"

PuzzleWin::PuzzleWin(sf::RenderWindow& window) : AWin(window)
{
  _picture = "./Ressources/Game/Picture/PuzzleWin.jpg";
  _good = false;
  _good = _pic.LoadFromFile(_picture); 
  _pictureSet = false;
  _diffSet = false;
}

PuzzleWin::~PuzzleWin()
{
}

void	PuzzleWin::setPicSet(bool isSet)
{
  _pictureSet = isSet;
}

void	PuzzleWin::setDiffSet(bool isSet)
{
  _diffSet = isSet;
}

void	PuzzleWin::setPic(std::string& pic)
{
}

bool	PuzzleWin::getPicSet() const
{
  return (_pictureSet);
}

bool	PuzzleWin::getDiffSet() const
{
  return (_diffSet);
}

void	PuzzleWin::drawDiff()
{
  Button*	diff;
  int	x = getWindow().GetWidth();
  int	y = getWindow().GetHeight();

  x /= 2;
  y /= 3;

  diff = new Button(x - 150, y - 50, x + 150, y + 50, "Easy");
  y+= 150;
  this->setType(MENU);
  diff->setWin(this);
  diff->setTarget(true);
  addButton(diff);
  diff = new Button(x - 150, y - 50, x + 150, y + 50, "Normal");
  y+= 150;
  diff->setWin(this);
  addButton(diff);
  diff = new Button(x - 150, y - 50, x + 150, y + 50, "Hard");
  y+= 150;
  diff->setWin(this);
  addButton(diff);
  getWindow().Display();
}

void	PuzzleWin::setDiff(std::string diff)
{
  _diff = diff;
}

std::string&	PuzzleWin::getDiff()
{
  return (_diff);
}

void	PuzzleWin::upUp()
{
  std::list<Button*>    but;
  std::list<Button*>::iterator  it;
  std::list<Button*>::iterator  itEnd;
  bool  on = false;
  bool  pass = false;

  but = this->getButton();
  it = but.begin();
  itEnd = but.end();
  itEnd--;
  while (on == false)
    {
      if ((*itEnd)->getTarget() == true)
        {
          on = true;
	  (*itEnd)->setTarget(false);
          if (it == itEnd)
            itEnd = but.end();
          itEnd--;
          (*itEnd)->setTarget(true);
	  this->setDiff((*itEnd)->getContent());
	  this->setDiffSet(true);
	}
      else if (itEnd == it)
        {
          itEnd = but.end();
          it--;
        }
      else
        itEnd--;
    }
}

void	PuzzleWin::upDown()
{
  std::list<Button*>    but;
  std::list<Button*>::iterator  it;
  std::list<Button*>::iterator  itEnd;
  bool  on = false;

  but = this->getButton();
  it = but.begin();
  itEnd = but.end();
  while (it != itEnd && on == false)
    {
      if ((*it)->getTarget() == true)
        {
          on = true;
          (*it)->setTarget(false);
          it++;
          if (it == itEnd)
            it = but.begin();
          (*it)->setTarget(true);
	  this->setDiff((*it)->getContent());
	  this->setDiffSet(true);
        }
      else
        it++;
    }
}

void	PuzzleWin::drawPic()
{
  DIR*	dir;
  struct dirent	*ent;
  struct stat	st;
  std::string	dos("./Ressources/Game/Puzzle/Pic/");
  std::string	name;
  std::string	fullName;
  sf::Image*	pic;
  sf::Sprite*	spr;
  int	x = 0;
  int	y = 50;
  int	litX = getWindow().GetWidth() / 4;
  int	litY = getWindow().GetHeight() / 2;

  this->setType(GAME);
  dir = opendir("./Ressources/Game/Puzzle/Pic");
  if (dir != NULL)
    {
      while ((ent = readdir(dir)) != NULL)
	{
	  name = ent->d_name;
	  fullName = dos + name;
	  if (name[0] != '.' && stat(fullName.c_str(), &st) != -1)
            if ((st.st_mode & S_IFDIR) == false)
              if (name.rfind('.') != std::string::npos && name.substr(name.rfind('.')).compare(".jpg") == 0)
		{
		  pic = new sf::Image;
		  if (pic->LoadFromFile(fullName) == true)
		    {
		      spr = new sf::Sprite;
		      spr->SetImage(*pic);
		      spr->SetPosition(x, y);
		      spr->Resize(150, 150);
		      getWindow().Draw(*spr);
		      x += 150 + 50;
		      if (x >= getWindow().GetWidth())
			{
			  x = 0;
			  y += 300;
			}
		    }
		}
	}
    }
}

void	PuzzleWin::mainDraw()
{
  PuzzleGame	*game;
  std::string	titlePic("Choose your Picture");
  std::string	titleDiff("Choose your Difficulty");
  sf::Event	event;
  sf::Event	last;
  bool		isIn = true;


  getWindow().Clear();
  if (getPicSet() == false)
    {
      drawTitle(titlePic);
      getWindow().Display();
      setPicSet(true);
      drawPic();
      getWindow().Display();
      sleep(10);
      mainDraw();
    }
  else if (getDiffSet() == false)
    {
      drawTitle(titleDiff);
      getWindow().Display();
      drawDiff();
      while (isIn == true)
	{
	  getWindow().GetEvent(event);
	  if (event.Type != 15 && event.Type != 10)
	    isIn = gestEvent(event);
	  if (event.Type != 10 && last.Type == 10)
	    isIn = gestEvent(last);
	  last = event;
	  drawTitle(titleDiff);
	  getWindow().Display();
	  usleep(40000);
	}
      setDiffSet(true);
    }
  else
    {
      game = new PuzzleGame(getWindow());
      game->mainGame();
      setPicSet(false);
      setDiffSet(false);
      this->setType(GAME);
    }
}

sf::Image&	PuzzleWin::getPic()
{
  return (_pic);
}

bool	PuzzleWin::isGood() const

{
  return (_good);
}

extern "C"
{

  AWin*	newWin(sf::RenderWindow& window)
  {
    return (new PuzzleWin(window));
  }

}
