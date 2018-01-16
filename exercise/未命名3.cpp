#include <iostream>
using namespace std;

class Cinlinder {
public:
	Cinlinder();
	void setLength(double l);
	void setWidth(double w);
	void setHeight(double h);
	void input();
	void getVolume();
	void computeVolume();
private:
	double length;
	double width;
	double height;
	double volume;
};

Cinlinder::Cinlinder()
{
	this->length = 0;
	this->width = 0;
	this->height = 0;
	this->volume = 0;
}

void Cinlinder::setLength(double l)
{
	this->length = l;
}

void Cinlinder::setWidth(double w)
{
	this->width = w;
}

void Cinlinder::setHeight(double h)
{
	this->height = h;
}
void Cinlinder::input()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> length >> width >> height;
		setLength(length);
		setWidth(width);
		setHeight(height);
		computeVolume();
		getVolume();
	}
	
}
void Cinlinder::computeVolume()
{
	volume = length * width * height;
}

void Cinlinder::getVolume()
{
	cout << volume << endl;
}


int main()
{
	Cinlinder c1;
	c1.input();
	return 0;
} 
