#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, k, won;
	int counter = 0;
	cin >> n >> k;
	vector <int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> won;
		v.insert(v.begin(), won);
	}
	v.rbegin();

	for (int j = 0; j < n; j++)
	{
		if ((k / v[j]) != 0)
		{
			counter += k / v[j];
			k = k % v[j];
		}
		if (k == 0) break;
	}

	cout << counter << endl;

	return 0;
}
