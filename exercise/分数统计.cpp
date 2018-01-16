#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int caseNum;
	cin >> caseNum;
	
	while (caseNum--)
	{
		int dataNum;
		cin >> dataNum;
		
		vector<double> vec;
		while (dataNum--)
		{
			double data;
			cin >> data;
			vec.push_back(data);
		}
		sort(vec.begin(), vec.end());
		double sum = 0;
		for (int i = 1; i < vec.size() - 1; i++)
		{
			sum += vec[i];
		}
		double score = sum * 1.0 / (vec.size() - 2);
		cout << fixed << setprecision(2) << score << endl;
	}
	
	return 0;
}
