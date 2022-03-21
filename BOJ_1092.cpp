#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	vector<int> crane;
	int input;
	int counter = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		crane.push_back(input);
	}

	int M;
	vector<int> cargo;
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		cargo.push_back(input);
	}

	// ũ���ΰ� ȭ���� ���� ������������ ����
	sort(crane.rbegin(), crane.rend());
	sort(cargo.rbegin(), cargo.rend());

	// ũ���� �ִ� ���ߺ��� ȭ�� �ִ� ���԰� ũ�� �ű� �� ����
	if (crane[0] < cargo[0]) {
		cout << -1 << endl;
		return 0;
	}
	
	// ȭ���� ��� �Ű��� ������
	while (!cargo.empty()) {
		// �� cycle�� ����� �� �ִ� ũ���ε�
		vector<int> tempCrane = crane;
		counter++; // ũ���� ��� cycle Ƚ�� count
		while (!tempCrane.empty() && !cargo.empty()) { // �� cycle�� ����� �� �ִ� ũ������ �����ְų� ��� ȭ���� ��� ���� �ű��� ���� ���
			for (int i = 0; i < (int)cargo.size(); ) { // cycle���� ���� ũ���� �� �ִ� ���� ũ������ �ű� �� �ִ� �ִ� ���� ȭ�� Ž��
				if (tempCrane.empty()) break; // cycle���� ����� �� �ִ� ũ������ ���� ��� Ž�� �����ϰ� ���� cycle��
				if (tempCrane[0] >= cargo[i]) { // ũ������ �ű� �� �ִ� �ִ� ���� ȭ���� ã�� ���
					tempCrane.erase(tempCrane.begin()); // cycle���� ����� �� �ִ� ũ������ �����ϰ�
					cargo.erase(cargo.begin() + i); // �ű� ȭ���� ����
					i = 0;
				}
				else { // ���� �ִ� ȭ���� �� ��� ȭ���� �ű� �� ���� ���
					i++;
					if(i == (int)cargo.size()) tempCrane.clear();
				}
			}

			if(!tempCrane.empty()) tempCrane.erase(tempCrane.begin());
		}
	}

	cout << counter << endl;

}