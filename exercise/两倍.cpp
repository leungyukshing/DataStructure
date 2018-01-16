#include <iostream>
using namespace std;

bool judge(int num1, int num2)
{
	if (((num1 * 2) == num2) || (num1 == (num2 * 2)))
	{
		return true;
	}
	return false;
}

int main()
{
	int caseNum;
	cin >> caseNum;
	
	while (caseNum--)
	{
		int count = 0;
		int dataNum;
		cin >> dataNum;
		int data[dataNum];
		int i = 0;
		int size = dataNum;
		while (dataNum--)
		{
			cin >> data[i++];
		}
		
		for (int j = 0; j < size; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				if (judge(data[j], data[k]))
				{
					count++;
				}
			}
		}
		cout << count << endl;
	}
	
	return 0;
}
