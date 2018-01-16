#include <iostream>
#define PI 3.14159
using namespace std;

int main()
{
	double radius = 0;
	double height = 0;
	
	cin >> radius >> height;
	double volume = radius * radius * PI * height;
	cout << volume << endl;
	
	return 0;
}
