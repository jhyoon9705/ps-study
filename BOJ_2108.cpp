// BOJ_2108 (https://www.acmicpc.net/problem/2108)
#include <bits/stdc++.h>

using namespace std;

double round_digit(double num, int d) { // 소수점 반올림
	double t = pow(10, d - 1);
	if (-1 < num && num < 0) { // -0.333...을 반올림할 경우 -0으로 계산되는 문제 해결
		return (fabs(round(num * t)) / t);
	}
	else {
		return round(num * t) / t;
	}
}

double average(const vector<int>& numbers) { // 산술 평균
	double sum = 0;
	for (unsigned int i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}

	return round_digit(sum / (double)numbers.size(), 1);
}

int medium(const vector<int>& numbers) { // 중앙값
	return numbers[(int)(numbers.size() / 2)];
}

int mode(const vector<int>& numbers) { // 최빈값(여러 개 있을 경우, 두 번째로 작은 값 출력)
	int maxCount = 1;
	int count = 1;
	vector<int> candidates; // 최빈값들의 후보값들을 모아두는 벡터

	if (numbers.size() >= 2) { 
		for (unsigned int i = 1; i < numbers.size(); i++) {
			if (numbers[i] == numbers[i - 1]) {
				count++;
			}
			if (numbers[i] != numbers[i - 1] || i == numbers.size() - 1) { // numbers[i] != numbers[i - 1]
				if (maxCount < count) {
					candidates.clear();
					candidates.push_back(numbers[i - 1]);
					maxCount = count;
				}
				else if (maxCount == count) {
					candidates.push_back(numbers[i - 1]);
				}

				count = 1;
			}

		}
	}

	if (candidates.size() >= 2) { // 최빈값들의 후보값이 2개 이상인 경우 두 번째로 작은 값 return
		return candidates[1];
	}
	else if(candidates.size() == 1){
		return candidates[0];
	}
	else { // 입력받은 값의 개수가 1개인 경우 그 수를 바로 return
		return numbers[0];
	}
	
}

int range(const vector<int>& numbers) { // 범위
	return numbers[numbers.size() - 1] - numbers[0];
}


int main() {
	int n, num;
	vector<int> v;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), less<int>()); // 오름차순으로 정렬

	cout << average(v) << endl; 
	cout << medium(v) << endl; 
	cout << mode(v) << endl; 
	cout << range(v) << endl;
}