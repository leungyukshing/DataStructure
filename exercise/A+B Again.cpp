#include <iostream>
using namespace std;

int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

int main()
{
	int caseNum;
	cin >> caseNum;
	
	while (caseNum--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		int numerator = a * d + b * c;
		int denominator = b * d;
		
		int divisor = gcd(numerator, denominator);
		numerator /= divisor;
		denominator /= divisor;
		
		if (denominator == 1)
		{
			cout << numerator << endl;
		}
		else
		{
			cout << numerator << "/" << denominator << endl;
		}
	}
	
	return 0;
}
