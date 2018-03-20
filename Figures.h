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
	Figures(int x=0, int y = 0, Colour colour=black); //// default-�� ����������� �� � ���������
	Figures(Figures const&); //���������������
	Figures& operator=(Figures const& f);
	~Figures();
	//��������
	void setX(int x);
	void setY(int y);
	void setColour(Colour colour);
	void translateVertical(int v); //��� ���� ��� ����������� ��������� ���� X � Y,����� �� ������� �� ������ ������, ��������� �� �� ���������
	void translateHorizontal(int h);
	//���������
	int getX() const;
	int getY() const;
	Colour getColour() const;

	static int getColour(const char* color); //�������� ������� ���������� �� ��������� �� print char*->int(Colour)
	static const char* getColour(int colorId); //�������� ������� ���������� �� ��������� �� print int->char*
	virtual void print(std::ostream& stream) const; //��������� ������� ������������� �� ����� ��������� 
	virtual void SVGify(std::ostream& stream) const;

	//������� �������� ������� �� ������ � ����� ���������� � .cpp
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

