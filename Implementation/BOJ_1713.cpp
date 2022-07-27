#include <bits/stdc++.h>

using namespace std;

int recommend[101] = { 0 };

int main() {

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> v(N);
    vector<int> candidates;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        recommend[num]++;

        bool change = true;
        for (int j = 0; j < N; j++) {

            if (v[j].second == 0) { // 남은 자리 존재
                v[j].first = i;
                v[j].second = num;
                change = false;
                break;
            }


            else if (v[j].second == num) { // 중복 추천
                change = false;
                break;
            }

        }

        if (change) {
            int index = 0;

            for (int j = 1; j < N; j++) {
                if (recommend[v[j].second] == recommend[v[index].second]) { // 푸펀 수 낮은 후보가 여러 명인 경우
                    if (v[j].first < v[index].first) { // 먼저 등록된 후보 찾기
                        index = j;
                    }
                }
                else if (recommend[v[j].second] < recommend[v[index].second]) { // 추천 수 제일 낮은 후보 찾기
                    index = j;
                }
            }

            recommend[v[index].second] = 0; // 후보가 바뀐 경우 추천수 초기화

            v[index].first = i;
            v[index].second = num;

        }
    }

    for (int i = 0; i < N; i++) {
        candidates.push_back(v[i].second);
    }

    sort(candidates.begin(), candidates.end());

    for (int i = 0; i < N; i++) {
        if (candidates[i] != 0) {
            cout << candidates[i] << " ";
        }
    }
}


