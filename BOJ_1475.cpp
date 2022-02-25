#include <bits/stdc++.h>

using namespace std;

int setNum = 0;

void newSet(vector<int>& set) { // 1 1 1 1 1 1 2 1 1 
	for (int i = 0; i < 9; i++) {
		set[i]++;
	}
	set[6]++;
	setNum++;
}

void use(vector<int>& set, int k) {
	if (k == 6 || k == 9) {
		if (set[6] == 0) {
			newSet(set);
		}
	 	set[6]--;
	}
	else {
		if (set[k] == 0)
		{
			newSet(set);
		}
		set[k]--;
	}
}

int main() {
	int roomNumber;
	vector<int> v;
	vector<int> numbers(9, 0);
	newSet(numbers);

	cin >> roomNumber;
	while (roomNumber != 0) { // separating the number of digits
		v.push_back(roomNumber % 10);
		roomNumber /= 10;
		
	}

	while(!v.empty()) { // use numbers
		int k = v.back();
		v.pop_back();
		use(numbers, k);
	}

	cout << setNum;
}