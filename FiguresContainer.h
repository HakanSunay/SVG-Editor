#pragma once
#include "Figures.h"
typedef unsigned int uint;


class FiguresContainer
{
private:
	Figures** _set; //масив от pointer-и към елементи от тип Figures,т.е Circle && Rectangle
	uint _size;
	uint _maxSize;
	void resize(); //в случай на препълнен контейнер се извиква функцията resize за увеличаване на размера контейнера
	void setFiguresContainer(Figures** set, uint size); //динамично заделяне на масив от pointer-и
public:
	FiguresContainer(Figures** set=nullptr,uint size=0,uint maxSize=100);
	FiguresContainer& operator=(FiguresContainer const& f);
	FiguresContainer(FiguresContainer const & copy);
	~FiguresContainer();

	void SVGify(std::ostream& stream) const; //превръща елементите на контейнера в SVG формат
	void print(std::ostream& stream) const; //извиква print функциите на всички елементи в контейнера
	void add(Figures *figs); //добавя динамично нови елементи в контейнера
	void remove(uint n); //премахва елементи от контейнера използвайки техният пореден номер в масива
	void translateX(int x); //транслира елементите на контейнера
	void translateY(int y); //транслира елементите на контейнера
	uint getSize() { return _size; }
};

