#include "Rectangle.h"
#include <iostream>


Rectangle::Rectangle(int x, int y, int width, int height, Colour colour) :
	Figures(x, y, colour), _width(width), _height(height)
{
	//_width = width;
}
//мутатори
void Rectangle::setHeight(int height)
{
	_height = height;
}
void Rectangle::setWidth(int width)
{
	_width = width;
}
//селектори
int Rectangle::getHeight() const
{
	return _height;
}
int Rectangle::getWidth() const
{
	return _width;
}
void Rectangle::print(std::ostream& stream) const
{
	stream << "rectangle" << " " << getX() << " " << getY() << " " << getWidth() << " " << getHeight() << " " << getColour((int)getColour()) << std::endl;
}
Rectangle::~Rectangle()
{
}

void Rectangle::SVGify(std::ostream& stream) const
{
	stream << "<rect x = " << getX() << " y = " << getY() << " width = " << getWidth() << " height = " << getHeight() << " fill =\"" << getColour() << "\" />";
}
