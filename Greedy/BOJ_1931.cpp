#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting {
	int start;
	int finish;
};

bool sorting(meeting a, meeting b) {
	if (a.finish == b.finish) {
		return a.start < b.start;
	}
	else return a.finish < b.finish;
}

int main() {
	int num;
	int i = 0;
	int counter = 0;
	
	cin >> num;
	vector <meeting> meetings(num);
	while (i<num) {
		cin >> meetings[i].start >> meetings[i].finish;
		i++;
	}
	sort(meetings.begin(), meetings.end(), sorting);
	
	int last = 0;
	int count = 0;

	for (int j = 0; j < num; j++) {
		if (last <= meetings[j].start) {
			last = meetings[j].finish;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}
