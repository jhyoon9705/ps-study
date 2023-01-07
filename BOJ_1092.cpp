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

	// 크레인과 화물을 무게 내림차순으로 정렬
	sort(crane.rbegin(), crane.rend());
	sort(cargo.rbegin(), cargo.rend());

	// 크레인 최대 하중보다 화물 최대 무게가 크면 옮길 수 없음
	if (crane[0] < cargo[0]) {
		cout << -1 << endl;
		return 0;
	}
	
	// 화물이 모두 옮겨질 때까지
	while (!cargo.empty()) {
		// 한 cycle에 사용할 수 있는 크레인들
		vector<int> tempCrane = crane;
		counter++; // 크레인 사용 cycle 횟수 count
		while (!tempCrane.empty() && !cargo.empty()) { // 한 cycle에 사용할 수 있는 크레인이 남아있거나 모든 화물을 모두 아직 옮기지 않은 경우
			for (int i = 0; i < (int)cargo.size(); ) { // cycle에서 남은 크레인 중 최대 하중 크레인이 옮길 수 있는 최대 무게 화물 탐색
				if (tempCrane.empty()) break; // cycle에서 사용할 수 있는 크레인이 없는 경우 탐색 종료하고 다음 cycle로
				if (tempCrane[0] >= cargo[i]) { // 크레인이 옮길 수 있는 최대 무게 화물을 찾은 경우
					tempCrane.erase(tempCrane.begin()); // cycle에서 사용할 수 있는 크레인을 제거하고
					cargo.erase(cargo.begin() + i); // 옮긴 화물도 제거
					i = 0;
				}
				else { // 남아 있는 화물들 중 어느 화물도 옮길 수 없는 경우
					i++;
					if(i == (int)cargo.size()) tempCrane.clear();
				}
			}

			if(!tempCrane.empty()) tempCrane.erase(tempCrane.begin());
		}
	}

	cout << counter << endl;

}