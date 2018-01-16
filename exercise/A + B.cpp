#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int caseNum = 0;
	cin >> caseNum;
	
	while(caseNum--)
	{
		string strnum1;
		string strnum2;
		int num1 = 0;
		int num2 = 0;
		
		cin >> strnum1 >> strnum2;
		
		for (int i = 0; i < strnum1.size(); i++)
		{
			num1 += ((strnum1[i]-'0') * pow(10, i));
		}
		
		for (int j = 0; j < strnum2.size(); j++)
		{
			num2 += ((strnum2[j]-'0') * pow(10, j));
		}
		
		int result = num1 + num2;
		cout << result << endl;
	}
	
	return 0;
}
