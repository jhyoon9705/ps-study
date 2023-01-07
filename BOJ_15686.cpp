// �� ���� ���Ͽ� m���� ġŲ�������� ġŲ�Ÿ��� ��� ���Ͽ� ���� ���� ���� �����ֱ�
#include <bits/stdc++.h>

using namespace std;

int n, m;
int MIN = 987654321;
vector<pair<int, int>> home, chicken, open;
bool selected[13];

void find_chicken_dist() {
	int result = 0;
	for (int i = 0; i < (int)home.size(); i++) { // �� ������
		int min_dist = 987654321;
		for (int j = 0; j < (int)open.size(); j++) { // ������ ġŲ���� ���Ͽ�
			min_dist = min(min_dist, abs(home[i].first - open[j].first) + abs(home[i].second - open[j].second)); // �ּ� ġŲ�Ÿ� ã��
		}
		result += min_dist; // ������ �ּ� ġŲ�Ÿ�
	}
	MIN = min(MIN, result);
}

void find_open_chicken(int x, int counter) {
	if (counter == m) {
		find_chicken_dist(); // m���� ġŲ���� �� ��, ġŲ�Ÿ��� �ּ��� ġŲ�� ã��
	}

	// m���� ġŲ�� ����
	for (int i = x; i < (int)chicken.size(); i++) {
		if (selected[i] == true) continue;

		selected[i] = true;
		open.push_back({ chicken[i].first, chicken[i].second });
		find_open_chicken(i, counter + 1);
		selected[i] = false;
		open.pop_back();
	}
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			if (input == 1) {
				home.push_back({ i, j });
			}
			else if (input == 2) {
				chicken.push_back({ i, j });
			}
		}
	}
	find_open_chicken(0, 0);
	cout << MIN;
	return 0;
}