#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> v;
vector<char> pw;
bool used[26];

bool conditionChecker(const vector<char>& pwVector) { // 자음, 모음 개수 조건 checking
	int consonant = 0; // 자음
	int vowel = 0; // 모음
	for (int i = 0; i < L; i++) {
		if (pwVector[i] == 'a' || pwVector[i] == 'e' || pwVector[i] == 'i' || pwVector[i] == 'o' || pwVector[i] == 'u') {
			vowel++;
		}
		else {
			consonant++;
		}
	}
	if (consonant >= 2 && vowel >= 1) {
		return true;
	}
	else {
		return false;
	}
}

void DFS(int idx, int counter) { // idx는 최근 사용한 알파벳, counter는 사용한 알파벳의 개수
	if (counter == L) {
		if (conditionChecker(pw)) {
			for (int i = 0; i < L; i++) {
				cout << pw[i];
			}
			cout << '\n';
		}		
		return;
	}

	for (int j = idx; j <  C; j++) {
		if (used[v[j] - 'a'] == false) {
			pw.push_back(v[j]);
			used[v[j] - 'a'] = true;
			DFS(j, counter + 1);
			// back-tracking
			pw.pop_back();
			used[v[j] - 'a'] = false;
		}
	}
}

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char input;
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end()); // 알파벳 순으로 정렬
	DFS(0, 0);

	return 0;
}