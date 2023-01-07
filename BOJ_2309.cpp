#include <bits/stdc++.h>
using namespace std;

// nPr 이용
int main() {
	int arr[9];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) sum += arr[i];
		if (sum == 100) break;
	} while (next_permutation(arr, arr + 9));
	
	for (int i = 0; i < 7; i++) cout << arr[i] << "\n";
	return 0;
}

// nCr 이용
/*int main() {
	vector<int> v;
	int input;
	int first = -1, second = -1;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> input;
		sum += input;
		v.push_back(input);
	}
	
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - v[i] - v[j] == 100) {
				v.erase(v.begin() + j);
				v.erase(v.begin() + i);
				break;
			}
		}
		if (v.size() == 7) {
			sort(v.begin(), v.end());
			break;
		}
	}

	for (int i = 0; i < 7; i++) cout << v[i] << '\n';

	return 0;
}*/

/* #include <iostream>
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
} */
