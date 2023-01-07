#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str, str2;
	int n, k;
	int j;
	int counter = 0;

	cin >> n >> k;
	cin >> str;

	str2.resize(k, 'A');
	str = str2 + str + str2;

	for (int i = k; i <= n + k ; i++) {
		if (str[i] == 'P')
		{
			j = i - k;
			while (str[j] != 'H' && abs(i - j) <= k)
			{
				j++;	
			}
			if ( abs(i-j) <= k)
			{
				str[j] = '0';
				counter++;
			}
		}
		
	}
	
	cout << counter;
	
	return 0;
}
