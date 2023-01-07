// 1439(뒤집기)
// 011011 -> 111111 (output: 2)
// 010010 -> 000000 (output: 2) 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	string text = "";
	int zeroGroup = 0;
	int oneGroup = 0;
	int temp = -1;

	cin >> text;

	for (int i = 0; i < (int)text.size(); i++) {
		if (text[i] == '0' && temp != 0) {
			temp = 0;
			zeroGroup++;
		}
		else if (text[i] == '1' && temp != 1) {
			temp = 1;
			oneGroup++;
		}
	}

	int result = zeroGroup >= oneGroup ? oneGroup : zeroGroup;
	cout << result;

	return 0;
}
