#include "Figures.h"
#include <iostream>


Figures::Figures(int x, int y, Colour colour)
{
	_x = x;
	_y = y;
	_colour = colour;
}
Figures::Figures(Figures const& f) //копиконструктор
{
	setX(f.getX());
	setY(f.getY());
	setColour(f.getColour());
}
Figures& Figures::operator=(Figures const& f)
{
	if (this != &f)
	{
		setX(f.getX());
		setY(f.getY());
		setColour(f.getColour());
	}
	return *this;
}
//Мутатори
void Figures::setX(int x)
{
	_x = x;
}
void Figures::setY(int y)
{
	_y = y;
}
void Figures::setColour(Colour colour)
{
	_colour = colour;
}
void Figures::translateVertical(int v)
{
	setY(getY() + v);
}
void Figures::translateHorizontal(int h)
{
	setX(getX() + h);
}
//селектори
int Figures::getX() const
{
	return _x;
}
int Figures::getY() const
{
	return _y;
}
Colour Figures::getColour() const
{
	return _colour;
}
int Figures::getColour(const char* color)
{
	if (compareStr(color,"black"))
	{
		return Colour::black;
	}
	else if (compareStr(color, "red"))
	{
		return Colour::red;
	}
	else if (compareStr(color, "yellow"))
	{
		return Colour::yellow;
	}
	else if (compareStr(color, "blue"))
	{
		return Colour::blue;
	}
	else if (compareStr(color, "green"))
	{
		return Colour::green;
	}
	return 0;
}
const char * Figures::getColour(int colorId)
{
	switch (colorId)
	{
	case Colour::black: return "black";
	case Colour::red: return "red";
	case Colour::blue: return "blue";
	case Colour::green: return "green";
	case Colour::yellow: return "yellow";
	default:
		return nullptr;
	}
}
void Figures::print(std::ostream& stream) const
{
	return;
}
void Figures::SVGify(std::ostream& stream) const
{
	return;
}
Figures::~Figures()
{
}
