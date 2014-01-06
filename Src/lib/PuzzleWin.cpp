#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "PuzzleGame.hh"
#include "PuzzleWin.hh"

PuzzleWin::PuzzleWin(sf::RenderWindow& window) : AWin(window)
{
  _picture = "./Ressources/Game/Picture/PuzzleWin.jpg";
  _good = false;
  _good = _pic.loadFromFile(_picture); 
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

void	PuzzleWin::setPic(std::string pic)
{
  _picturePuzz = pic;
  pic = "./Ressources/Game/Puzzle/Pic/" + pic;
  _good = _pic.loadFromFile(pic);
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
  int	x = getWindow().getSize().x;
  int	y = getWindow().getSize().y;

  x /= 2;
  y /= 3;
  diff = new Button(x - 150, y - 50, x + 150, y + 50, "Easy");
  y+= 150;
  this->setType(MENU);
  diff->setWin(this);
  diff->setTarget(true);
  this->setDiff("Easy");
  addButton(diff);
  diff = new Button(x - 150, y - 50, x + 150, y + 50, "Normal");
  y+= 150;
  diff->setWin(this);
  addButton(diff);
  diff = new Button(x - 150, y - 50, x + 150, y + 50, "Hard");
  y+= 150;
  diff->setWin(this);
  addButton(diff);
  getWindow().display();
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
	  if (getDiffSet() == false)
	    this->setPic((*itEnd)->getContent());
	  else
	    this->setDiff((*itEnd)->getContent());
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
	  if (getDiffSet() == false)
	    this->setPic((*it)->getContent());
	  else
	    this->setDiff((*it)->getContent());
	}
      else
        it++;
    }
}

void	PuzzleWin::loadPic(std::list<sf::Sprite*> &_spr)
{
  DIR*	dir;
  struct dirent	*ent;
  struct stat	st;
  std::string	dos("./Ressources/Game/Puzzle/Pic/");
  std::string	name;
  std::string	fullName;
  sf::Texture*	pic;
  sf::Sprite*	spr;
  int	x = 25;
  int	y = 50;
  int	litX = getWindow().getSize().x / 4;
  int	litY = getWindow().getSize().y / 2;
  Button	*next;

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
		  pic = new sf::Texture;
		  if (pic->loadFromFile(fullName) == true)
		    {
		      next = new Button(x, y, x + 175, y + 175, name);
		      if (x == 25 && y == 50)
			{			
			  this->setPic(next->getContent());
			  next->setTarget(true);
			}
		      addButton(next);
		      this->setType(MENU);
		      next->setWin(this);
		      next->DrawContent(getWindow());
		      spr = new sf::Sprite;
		      spr->setTexture(*pic);
		      spr->setPosition(x, y+50);
		      spr->setScale(0.2f, 0.25f);
		      getWindow().draw(*spr);
		      _spr.push_front(spr);
		      x += 150 + 50;
		      if (x >= getWindow().getSize().x)
			{
			  x = 0;
			  y += 300;
			}

		    }
		}
	}
    }
}

void	PuzzleWin::drawPic(std::list<sf::Sprite*>& spr)
{
  std::list<sf::Sprite*>::iterator	it = spr.begin();
  std::list<sf::Sprite*>::iterator	itEnd = spr.end();

  while (it != itEnd)
    {
      getWindow().draw(*(*it));
      it++;
    }
}

bool	PuzzleWin::gestMove(sf::Event &event)
{/*
  if (event.Type == sf::Event::MouseMoved)
    {
      mX = event.MouseMove.X;
      mY = event.MouseMove.Y;
      it = but.begin();
      itEnd = but.end();
      while (it != itEnd)
        {
          if ((*it)->isIn(mX, mY) == true)
            {
              itNew = it;
              (*it)->setTarget(true);
	      if (getDiffSet() == false)
		this->setPic((*it)->getContent());
	      else
		this->setDiff((*it)->getContent());          
	      newCur = true;
            }
          it++;
        }
      it = but.begin();
      while (it != itEnd && newCur == true)
        {
          if (it != itNew)
            (*it)->setTarget(false);
          it++;
        }
	}*/
}

void	PuzzleWin::mainDraw()
{
  PuzzleGame	*game;
  std::string	titlePic("Choose your Picture");
  std::string	titleDiff("Choose your Difficulty");
  sf::Event	event;
  sf::Event	last;
  bool		isIn = true;
  std::list<sf::Sprite*>	spr;

  getWindow().clear();
  if (getPicSet() == false)
    {
      drawTitle(titlePic);
      getWindow().display();
      setPicSet(true);
      loadPic(spr);
      getWindow().display();
      sleep(1);
      while (isIn == true)
	{
	  getWindow().pollEvent(event);
	  if (event.type != 15 && event.type != 10)
	    isIn = gestEvent(event);
	  if (event.type != 10 && last.type == 10)
	    isIn = gestMove(last);
	  last = event;
	  drawTitle(titlePic);
	  drawPic(spr);
	  getWindow().display();
	  usleep(40000);
	}

    }
  else if (getDiffSet() == false)
    {
      drawTitle(titleDiff);
      getWindow().display();
      drawDiff();
      setDiffSet(true);
      while (isIn == true)
	{
	  getWindow().pollEvent(event);
	  if (event.type != 15 && event.type != 10)
	    isIn = gestEvent(event);
	  if (event.type != 10 && last.type == 10)
	    isIn = gestMove(last);
	  last = event;
	  drawTitle(titleDiff);
	  getWindow().display();
	  usleep(40000);
	}
      this->setType(GAME);  
    }
  else
    {
      game = new PuzzleGame(getWindow());
      game->mainGame(_pic, _diff);
      setPicSet(false);
      setDiffSet(false);
      this->setType(GAME);
    }
}

sf::Texture&	PuzzleWin::getPic()
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
