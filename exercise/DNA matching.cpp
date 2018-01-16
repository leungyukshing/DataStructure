#include <iostream>
#include <string>
using namespace std;

bool judge(string s1, string s2)
{
	if (s1.size() != s2.size())
	{
		return false;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == 'A' && s2[i] == 'T')
		{
			continue;
		}
		else if (s1[i] == 'T' && s2[i] == 'A')
		{
			continue;
		}
		else if (s1[i] == 'C' && s2[i] == 'G')
		{
			continue;
		}
		else if (s1[i] == 'G' && s2[i] == 'C')
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	
	return true;
}
int main()
{
	int caseNumber = 0;
	cin >> caseNumber;
	
	while (caseNumber--)
	{
		int strandNumber = 0;
		cin >> strandNumber;
		int size = strandNumber;
		int i = 0;
		string strands[size];
		while (strandNumber--)
		{
			cin >> strands[i++];
		}
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				if (judge(strands[j], strands[k]))
				{
					count++;
					strands[j] = "";
					strands[k] = "";
					break;
				}
			}
		}
		
		cout << count << endl;
	}
	
	return 0;
}
