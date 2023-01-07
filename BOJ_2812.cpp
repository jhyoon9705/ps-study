// ���ڿ��� ���� ������ ������ pop, ������ �ϴ� ����(k) ����
// dequeue�� ���ڿ� ����

#include <bits/stdc++.h>

using namespace std;

int n, k;
string val;
deque<char> deq;
int main() {
	int n, k;
	cin >> n >> k;
	cin >> val;

	for (int i = 0; i < val.length(); i++) {

		while (k != 0 && !deq.empty() && deq.back() < val[i]) {
			deq.pop_back();
			k--;
		}
		deq.push_back(val[i]);
	}
	for (int i = 0; i < deq.size() - k; i++) {
		cout << deq[i];
	}

	return 0;
}

// =========�ð� �ʰ�=============
/* 
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> numbers;
vector<int> answer;
int toErase, idx;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%1d", &input);
		numbers.push_back({ input });
	}

	toErase = K;

	while ((int)answer.size() < N - K) {
		vector<int> temp(numbers.begin(), numbers.end());
		sort(temp.begin(), temp.begin() + toErase + 1, cmp);
		answer.push_back(temp[0]);
		while (temp[0] != numbers[0]) {
			numbers.erase(numbers.begin());
			toErase--;
		}
		numbers.erase(numbers.begin());

	}

	for (int i = 0; i < (int)answer.size(); i++) {
		cout << answer[i];
	}
	return 0;
} 
*/