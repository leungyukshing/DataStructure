#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		if (str == "XXX")
		{
			return 0;
		}
		string output;
		for (int i = 0; i < str.size(); i++)
		{
			if ( str[i] >= '0' && str[i] <= '9')
			{
				string time;
				int j;
				for (j = i; j < str.size(); j++)
				{
					if( str[j] >= '0' && str[j] <= '9')
					{
						time += str[j];
					}
					else
					{
						break;
					}
				}
				int times = atoi(time.c_str()) - 1;
				while (times--)
				{
					output += str[i - 1];
				}
				i = j - 1;
			}
			else
			{
				output += str[i];
			}
		}
		
		cout << output << endl;
	}
	return 0;
}
