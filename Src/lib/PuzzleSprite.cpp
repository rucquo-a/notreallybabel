#include "PuzzleSprite.hh"

PuzzleSprite::PuzzleSprite(int id, int pos)
{
  _id = id;
  _pos = pos;
  _isSelect = false;
}

PuzzleSprite::~PuzzleSprite()
{
}

sf::Sprite	&PuzzleSprite::getSprite()
{
  return (_pic);
}

void	PuzzleSprite::setPos(int pos)
{
  _pos = pos;
}

int	PuzzleSprite::getPos() const
{
  return (_pos);
}

bool	PuzzleSprite::getSelect() const
{
  return (_isSelect);
}

void	PuzzleSprite::setSelect(bool is)
{
  _isSelect = is;
}


void	PuzzleSprite::setId(int id)
{
  _id = id;
}

void	PuzzleSprite::setSprite(sf::Sprite& spr)
{
  _pic = spr;
}
