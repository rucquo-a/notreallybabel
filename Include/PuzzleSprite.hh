#ifndef __PUZZLESPRITE_HH__
#define __PUZZLESPRITE_HH__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class	PuzzleSprite
{
  int		_id;
  sf::Sprite	_pic;
  int		_pos;
  bool		_isSelect;		

public:
  PuzzleSprite(int, int);
  ~PuzzleSprite();
  void		setSelect(bool);
  bool		getSelect() const;
  sf::Sprite	&getSprite();
  int		getId() const;
  int		getPos() const;
  void		setPos(int);
};


#endif
