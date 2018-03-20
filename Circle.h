#pragma once
#include "Figures.h"
#include <iostream>
class Circle : public Figures
{
protected:
	int _radius;
public:
	Circle(int x = 0, int y = 0, int radius = 0, Colour colour = Colour::black);
	//Circle(Circle const& copy);
	//Circle& operator=(Circle const& f);
	~Circle();
	//��������
	void setRadius(int radius);
	//���������
	int getRadius() const;
	void print(std::ostream& stream) const;
	void SVGify(std::ostream& stream) const;

	//������������ ���� : ���������� �� ��������<< �� ��������� �� ������������ ��� ��������� �� print
	/*friend std::ostream& operator<<(std::ostream& out, Circle const& circ)
	{
		circ.SVGify(out);
		return out;
	}*/
};

