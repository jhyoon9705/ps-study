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

            if (v[j].second == 0) { // ���� �ڸ� ����
                v[j].first = i;
                v[j].second = num;
                change = false;
                break;
            }


            else if (v[j].second == num) { // �ߺ� ��õ
                change = false;
                break;
            }

        }

        if (change) {
            int index = 0;

            for (int j = 1; j < N; j++) {
                if (recommend[v[j].second] == recommend[v[index].second]) { // Ǫ�� �� ���� �ĺ��� ���� ���� ���
                    if (v[j].first < v[index].first) { // ���� ��ϵ� �ĺ� ã��
                        index = j;
                    }
                }
                else if (recommend[v[j].second] < recommend[v[index].second]) { // ��õ �� ���� ���� �ĺ� ã��
                    index = j;
                }
            }

            recommend[v[index].second] = 0; // �ĺ��� �ٲ� ��� ��õ�� �ʱ�ȭ

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


