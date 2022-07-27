#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector <int> heightVec;
	int temp;
	int heightSum = 0;
	int a = 0, b = 0;

	for(int i=0; i<9; i++)
	{
		cin >> temp;
		heightVec.push_back(temp);
		heightSum += heightVec[i];
	}

	vector <int>::iterator iter = heightVec.begin();
	vector <int>::iterator iter2 = heightVec.begin();

	for (iter=heightVec.begin(); iter!=heightVec.end()-1; iter++)
	{
		for (iter2 = iter + 1;  iter2 != heightVec.end() ; iter2++)
			if (heightSum - *iter - *iter2 == 100)	goto HUND;
		
	}
	HUND:
	heightVec.erase(iter2);
	heightVec.erase(iter);
	sort(heightVec.begin(), heightVec.end());

	for (int j = 0; j < (int)heightVec.size(); j++)	cout << heightVec[j] << endl;
		
	return 0;
}
