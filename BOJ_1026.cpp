#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A, B;
	int input;
	int result = 0;

	for (int i = 0; i < N; i++) {
		cin >> input;
		A.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		cin >> input;
		B.push_back(input);
	}

	sort(A.begin(), A.end());

	vector<int> Btemp;
	Btemp.resize((int)(B.size()));
	copy(B.begin(), B.end(), Btemp.begin());

	sort(Btemp.rbegin(), Btemp.rend());

	for (int j = 0; j < N; j++) {
		result += A[j] * Btemp[j];
	}

	cout << result << endl;

}