#ifndef	__PuzzleWin_HH__
#define	__PuzzleWin_HH__

#include	"Button.hh"
#include	"AWin.hh"
#include	<list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class	PuzzleWin : public AWin
{
  std::string	_picture;
  sf::Image	_pic;
  bool		_good;
  bool		_pictureSet;
  bool		_diffSet;
  std::string	_diff;

public:
  void		drawDiff();
  virtual void		upUp();
  virtual void		upDown();
  void			drawPic();
  bool		getPicSet() const;
  bool		getDiffSet() const;
  void		setPicSet(bool);
  void		setDiffSet(bool);
  void		setDiff(std::string);
  std::string&	getDiff();
  void		setPic(std::string&);
  sf::Image&	getPic();
  bool	isGood() const;
  PuzzleWin(sf::RenderWindow&);
  virtual ~PuzzleWin();
  virtual void	mainDraw();
};

#endif
