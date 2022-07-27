#include <iostream>
#include <vector>
using namespace std;
const int credit = 1000;

int main(void)
{
	int money, change;
	int num = 0;
	vector<int> v;
	v.push_back(500);
	v.push_back(100);
	v.push_back(50);
	v.push_back(10);
	v.push_back(5);
	v.push_back(1);

	cin >> money;

	change = credit - money;

	for (int i = 0; i < (int)v.size(); i++)
	{
		if (change / v[i] != 0)
		{
			num += change / v[i];
			change %= v[i];
		}
	}
	cout << num << endl;

	return 0;

}
