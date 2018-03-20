//Хакан Сунай Халил, ФН:81406, 1ви курс, 1ви поток, 2ра група
//Проект 2: Работа със SVG файлове
#include <iostream>
#include <fstream>
#include "Figures.h"
#include "Circle.h"
#include "Rectangle.h"
#include "FiguresContainer.h"

using namespace std;

int strLen(const char* str)
{
	int size = 0;
	while (*str++)
		size++;
	return size;
}
bool compareStr(const char* main, const char* dir)
{
	if (strLen(main)!=strLen(dir))
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
int a2i(char *str)
{
	int num = 0;
	while ((*str)>='0' && (*str)<='9')
	{
		num = ((*str)-'0') + num * 10;
		str++;
	}
	return num;
}
int findVertNum(char* str)
{
	char* start = strstr(str, "cal=");
	int value = a2i(start += 4);
	return value;
}
int findHorizNum(char* str)
{
	char* start = strstr(str, "tal=");
	int value = a2i(start += 4);
	return value;
}
int findX(char* str) 
{
	char* start = strstr(str, "x=\"");
	int value = a2i(start+=3);
	return value;
}
int findY(char* str)
{
	char* start = strstr(str, "y=\"");
	int value = a2i(start+=3);
	return value;
}
int findWidth(char* str)
{
	char* start = strstr(str, "width=\"");
	int value = a2i(start+=7);
	return value;
}
int findHeight(char* str)
{
	char* start = strstr(str, "height=\"");
	int value = a2i(start+=8);
	return value;
}
int findRadius(char* str)
{
	char* start = strstr(str, "r=\"");
	int value = a2i(start+=3);
	return value;
}
Colour findColour(char* str)
{
	char* start = strstr(str, "fill=\"");
	start += 6;
	if (strstr(start,"green"))
	{
		return green;
	}
	else if (strstr(start, "red"))
	{
		return red;
	}
	else if (strstr(start, "blue"))
	{
		return blue;
	}
	else if (strstr(start, "black"))
	{
		return black;
	}
	else if (strstr(start, "green"))
	{
		return yellow;
	}
	return black;
}
int main()
{
	
	char location[20];
	char open[4];
	cin >> open;
	cin >> location;	
	ifstream svg(location);
	if (strcmp(open,"open") == 0)
	{
		cout << "Successfully opened " << location << endl;
	}

	FiguresContainer svgCon;
	const int maxLine = 100;
	char line[maxLine];
	bool shouldRead = false;
	while (svg)
	{
		svg.getline(line, maxLine - 1);
		if (compareStr(line, "</svg>"))
		{
			shouldRead = false;
			break;
		}
		if (shouldRead)
		{
			if (strstr(line, "<rect"))
			{
				svgCon.add(new Rectangle(findX(line), findY(line), findWidth(line), findHeight(line), findColour(line)));	
			}
			else if (strstr(line, "<circle"))
			{
				svgCon.add(new Circle(findX(line), findY(line), findRadius(line), findColour(line)));
			}
			continue;
		}
		if (compareStr(line,"<svg>"))
			shouldRead = true;
	}
	char command[20];
	cin >> command;
	while (!compareStr(command,"exit"))
	{
		if (compareStr(command,"print"))
		{
			svgCon.print(cout);
		}
		else if (compareStr(command, "create"))
		{
			char type[10];
			cin >> type;
			if (compareStr(type,"rectangle"))
			{
				int x, y, width, height;
				char color[8];
				cin >> x >> y >> width >> height >> color;
				svgCon.add(new Rectangle(x, y, width, height, (Colour) Figures::getColour(color)));
			}
			else if (compareStr(type, "circle"))
			{
				int x, y, radius;
				char color[8];
				cin >> x >> y >> radius >> color;
				svgCon.add(new Circle(x, y, radius, (Colour)Figures::getColour(color)));
			}
		}
		else if (compareStr(command, "erase"))
		{
			int num;
			cin >> num;
			if (num<=svgCon.getSize())
			{
				svgCon.remove(num);
			}
			else
			{
				cout << "There is no figure number " << num << "!" << endl;
			}
		}
		else if (compareStr(command, "translate"))
		{
			char vertical[25];
			char horizontal[25];
			cin >> vertical >> horizontal;
			findHorizNum(horizontal);
			findVertNum(vertical);
			svgCon.translateX(findHorizNum(horizontal));
			svgCon.translateY(findVertNum(vertical));
			cout << "Translated all figures" << endl;

		}
		else if (compareStr(command, "within"))
		{

		}
		else if (compareStr(command, "save"))
		{
			ofstream newSvg(location, std::ios::trunc);
			newSvg << "<svg>" << std::endl;
			svgCon.SVGify(newSvg);
			newSvg << "</svg>";
			cout << "Successfully saved the changes to " << location << endl;
		}
		cin >> command;
	}
	cout << "Exit";
	svg.close();
    return 0;
}