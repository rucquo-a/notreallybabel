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

void	PuzzleWin::setPic(std::string pic)
{
  _picture = pic;
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
  sf::Image*	pic;
  sf::Sprite*	spr;
  int	x = 25;
  int	y = 50;
  int	litX = getWindow().GetWidth() / 4;
  int	litY = getWindow().GetHeight() / 2;
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
		  pic = new sf::Image;
		  if (pic->LoadFromFile(fullName) == true)
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
		      spr->SetImage(*pic);
		      spr->SetPosition(x, y+50);
		      spr->Resize(150, 150);
		      getWindow().Draw(*spr);
		      _spr.push_front(spr);
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

void	PuzzleWin::drawPic(std::list<sf::Sprite*>& spr)
{
  std::list<sf::Sprite*>::iterator	it = spr.begin();
  std::list<sf::Sprite*>::iterator	itEnd = spr.end();

  while (it != itEnd)
    {
      getWindow().Draw(*(*it));
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

  getWindow().Clear();
  if (getPicSet() == false)
    {
      drawTitle(titlePic);
      getWindow().Display();
      setPicSet(true);
      loadPic(spr);
      getWindow().Display();
      sleep(1);
      while (isIn == true)
	{
	  getWindow().GetEvent(event);
	  if (event.Type != 15 && event.Type != 10)
	    isIn = gestEvent(event);
	  if (event.Type != 10 && last.Type == 10)
	    isIn = gestMove(last);
	  last = event;
	  drawTitle(titlePic);
	  drawPic(spr);
	  getWindow().Display();
	  usleep(40000);
	}

    }
  else if (getDiffSet() == false)
    {
      drawTitle(titleDiff);
      getWindow().Display();
      drawDiff();
      setDiffSet(true);
      while (isIn == true)
	{
	  getWindow().GetEvent(event);
	  if (event.Type != 15 && event.Type != 10)
	    isIn = gestEvent(event);
	  if (event.Type != 10 && last.Type == 10)
	    isIn = gestMove(last);
	  last = event;
	  drawTitle(titleDiff);
	  getWindow().Display();
	  usleep(40000);
	}
      this->setType(GAME);  
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
