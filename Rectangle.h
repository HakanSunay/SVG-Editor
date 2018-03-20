#include "Figures.h"
#include <iostream>
#pragma once
class Rectangle : public Figures 
{
protected:
	int _height;
	int _width;
public:
	Rectangle(int x=0, int y=0, int width=0, int height=0, Colour colour=Colour::black);
	~Rectangle();
	//��������
	void setHeight(int height);
	void setWidth(int width);
	//���������
	int getHeight() const;
	int getWidth() const;
	void print(std::ostream& stream) const;
	void SVGify(std::ostream& stream) const;

	//������������ ���� : ���������� �� ��������<< �� ��������� �� ������������ ��� ��������� �� print
	/*friend std::ostream& operator<<(std::ostream& out, Rectangle const& rect)
	{
		rect.SVGify(out);
		return out;
	}*/
};

