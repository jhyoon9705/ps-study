#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	return a.first > b.first;
}

int main() {
	int totalPay = 0;
	int num;
	cin >> num;

	vector<pair<int, int>> v;

	int dInput, pInput;
	int d, p;
	int lecture[10000] = { 0 }; // ���� ������ �迭(0�̸� ����, 1�̸� ����)

	for (int i = 0; i < num; i++) {
		cin >> pInput >> dInput;
		v.push_back(make_pair(pInput, dInput));
	}

	// �����ᰡ ���� ������ ����
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < num; i++) {
		d = v[i].second;
		p = v[i].first;

		while (d != 0) { // ���� ���� ��¥ �߿��� �� ��¥�� ���� ������ Ž��
			if (lecture[d - 1] == 0) { // ����ִ� ��¥�� ������
				lecture[d - 1] = 1; // ������ �ϰ�
				totalPay += p; // �����Ḧ ����
				break;
			}
			d--;
		}
	}

	cout << totalPay << endl;

}