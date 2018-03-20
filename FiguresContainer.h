#pragma once
#include "Figures.h"
typedef unsigned int uint;


class FiguresContainer
{
private:
	Figures** _set; //����� �� pointer-� ��� �������� �� ��� Figures,�.� Circle && Rectangle
	uint _size;
	uint _maxSize;
	void resize(); //� ������ �� ��������� ��������� �� ������� ��������� resize �� ����������� �� ������� ����������
	void setFiguresContainer(Figures** set, uint size); //��������� �������� �� ����� �� pointer-�
public:
	FiguresContainer(Figures** set=nullptr,uint size=0,uint maxSize=100);
	FiguresContainer& operator=(FiguresContainer const& f);
	FiguresContainer(FiguresContainer const & copy);
	~FiguresContainer();

	void SVGify(std::ostream& stream) const; //�������� ���������� �� ���������� � SVG ������
	void print(std::ostream& stream) const; //������� print ��������� �� ������ �������� � ����������
	void add(Figures *figs); //������ ��������� ���� �������� � ����������
	void remove(uint n); //�������� �������� �� ���������� ����������� ������� ������� ����� � ������
	void translateX(int x); //��������� ���������� �� ����������
	void translateY(int y); //��������� ���������� �� ����������
	uint getSize() { return _size; }
};

