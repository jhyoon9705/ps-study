#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}


int main() {
	int N;
	cin >> N;

	int total = 0;
	vector<pair<int, int>> hw;
	int did[1000] = { 0 };

	int time, point;
		
	for (int i = 0; i < N; i++) {
		cin >> time >> point;
		hw.push_back(make_pair(time, point));
	}

	// ���� ��� ���� ������ ����
	sort(hw.begin(), hw.end(), cmp);

	// ������ ū �������� ä�������� �� ������ �ִ��� �ʰ� ����(n�ϱ����� 1~n�� �� �� �� �ִ� ���� ����������)
	for (int i = 0; i < N; i++) {
		int myTime = hw[i].first;
		int myPoint = hw[i].second;

		int pointer = myTime - 1;
		while (pointer >= 0) {
			if (did[pointer] == 0) {
				did[pointer] = myPoint;
				break;
			}
			pointer--;
		}
	}

	for (int j = 0; j < 1000; j++) {
		total += did[j];
	}
	
	cout << total << endl;
}