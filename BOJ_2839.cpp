#include <iostream>
using namespace std;
const int three = 3;
const int five = 5;

int main(void)
{
	int num = 0;
	int weight;
	int range = 0;

	cin >> weight;
	range = weight / five;
	for (int i = range; i >= 0; i--)
	{
		weight -= five * i;
		if (weight % 3 == 0)
		{
			num += i + (weight / 3);
			cout << num << endl;
			break;
			
		}
		weight += five * i;
	}
	if (num == 0)
		cout << -1 << endl;

	return 0;

}