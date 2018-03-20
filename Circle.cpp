#include "Circle.h"

Circle::Circle(int x, int y, int radius, Colour colour) :
	Figures(x,y,colour), _radius(radius)
{
}
/*Circle::Circle(Circle const & copy)
{
	_x = copy.getX();
	_y = copy.getY();
	_colour = copy.getColour();
	_radius = copy.getRadius();
}
Circle & Circle::operator=(Circle const & f)
{
	Figures::operator=(f);
	setRadius(f.getRadius());
	return *this;
}
*/
//мутатори
void Circle::setRadius(int radius)
{
	_radius = radius;
}
//селектори
int Circle::getRadius() const
{
	return _radius;
}
void Circle::print(std::ostream& stream) const
{
	stream << "circle" << " " << getX() << " " << getY() << " " << getRadius() << " " << getColour((int)getColour()) << std::endl;
}
void Circle::SVGify(std::ostream & stream) const
{
	stream << "<circle cx = " << getX() << " cy = " << getY() << " r = " << getRadius() << " fill =\"" << getColour() << "\" />";
}
Circle::~Circle()
{
}
