#include "FiguresContainer.h"

void FiguresContainer::resize()
{
	//преместваме елементите на стария масив в нов
	Figures** temp;
	temp = new Figures*[_size];
	for (uint i = 0; i < _size; i++)
	{
		temp[i] = new Figures(*_set[i]);
	}
	//изтриваме стария масив
	for (uint i = 0; i < _size; i++) {
		delete _set[i];
	}
	//създаваме нов динамичен масив с размер двоен на предишния
	_set = new Figures*[_size*2];
	for (uint i = 0; i < _size; i++)
	{
		_set[i] = new Figures(*temp[i]);
	}
	//увеличаваме новият максимален размер
	_size *= 2;
	_maxSize *= 2;
}

FiguresContainer::FiguresContainer(Figures ** set, uint size, uint maxSize)
	: _set(nullptr),_size(size),_maxSize(maxSize)
{
	setFiguresContainer(set,size);
}

FiguresContainer & FiguresContainer::operator=(FiguresContainer const & f)
{
	_size = f._size;
	_maxSize = f._maxSize;
	setFiguresContainer(f._set,f._size);
	return *this;
}

FiguresContainer::FiguresContainer(FiguresContainer const & copy)
{
	setFiguresContainer(copy._set,copy._size);
	_size = copy._size;
	_maxSize = copy._maxSize;
}

FiguresContainer::~FiguresContainer()
{
	for (uint i = 0; i < _size; i++) {
		delete _set[i];
	}
	delete[] _set;
}

void FiguresContainer::setFiguresContainer(Figures ** set,uint size)
{
	//изтриваме
	delete[] _set;
	//заделяме динамично
	_set = new Figures*[size];
	for (uint i = 0; i < _size; i++)
	{
		_set[i] = set[i];
	}
}

void FiguresContainer::SVGify(std::ostream & stream) const
{
	for (uint i = 0; i < _size; i++)
	{
		if (_set[i]) // подсигуряваме се
		{
			_set[i]->SVGify(stream);
			stream << std::endl;
		}
		
	}
}

void FiguresContainer::print(std::ostream& stream) const
{
	for (int i = 0; i < _size; i++)
	{
		stream << i + 1 << ". ";
		if (_set[i])
		{
			_set[i]->print(stream);
		}
	}
}

void FiguresContainer::add(Figures * figs)
{
	if (_size==_maxSize)
		resize();
	_set[_size] = figs;
	_size++;
}

void FiguresContainer::remove(uint n)
{
	if (n<1 || n>=_size)
	{
		return;
	}
	//поради несъответствие между въведаната стойност и номера на елемента в масива
	_set[n-1] = nullptr;
	for (uint i = n-1; i <_size-1; i++)
	{
		_set[i] = _set[i + 1];
	}
	_size--;
}

void FiguresContainer::translateX(int x)
{
	for (uint i = 0; i < _size; i++)
	{
		_set[i]->setX((_set[i]->getX()) + x);
	}
}

void FiguresContainer::translateY(int y)
{
	for (uint i = 0; i < _size; i++)
	{
		_set[i]->setY((_set[i]->getY()) + y);
	}
}
