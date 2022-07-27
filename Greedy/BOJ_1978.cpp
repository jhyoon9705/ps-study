#include <iostream>
using namespace std;

bool isPrime(int num)
{
	int temp = 0;

	if (num == 0 || num == 1) return false;

	for(int i = 1; i <= num; i++)
		if (num % i == 0) temp++;
	
	if (temp == 2) return true;
	else return false;
}


int main() 
{
	int n;
	int counter = 0;
	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;

		if (isPrime(num) == true)
			counter++;
	}
	cout << counter << endl;

	return 0;
}
