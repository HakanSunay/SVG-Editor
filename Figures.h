#pragma once
enum Colour { red, blue, green, yellow, black };
#include <iostream>
class Figures
{
protected:
	int _x;
	int _y;
	Colour _colour;

public:
	Figures(int x=0, int y = 0, Colour colour=black); //// default-ен конструктор §§ с параметри
	Figures(Figures const&); //копиконструктор
	Figures& operator=(Figures const& f);
	~Figures();
	//мутатори
	void setX(int x);
	void setY(int y);
	void setColour(Colour colour);
	void translateVertical(int v); //тъй като при транслиране променяме само X и Y,които са валидни за всички фигури, функциите не са виртуални
	void translateHorizontal(int h);
	//селектори
	int getX() const;
	int getY() const;
	Colour getColour() const;

	static int getColour(const char* color); //статична функция използвана за улеснение на print char*->int(Colour)
	static const char* getColour(int colorId); //статична функция използвана за улеснение на print int->char*
	virtual void print(std::ostream& stream) const; //виртуални функции предефинирани за всеки наследник 
	virtual void SVGify(std::ostream& stream) const;

	//помощни статични функции за работа с текст използвани в .cpp
	static bool compareStr(const char* main, const char* dir)
	{
		if (strLen(main) != strLen(dir))
		{
			return false;
		}
		for (int i = 0; i < strLen(main); i++)
		{
			if (main[i] != dir[i])
				return false;
		}
		return true;

	}
	static int strLen(const char* str)
	{
		int size = 0;
		while (*str++)
			size++;
		return size;
	}
};

