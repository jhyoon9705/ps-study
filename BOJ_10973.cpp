// 1. �迭�� �ں��� 2���� ���ϸ鼭 ���� ���ڰ� �� ū ��� ã��
// 2. �� ���ڰ� �� ū �κ��� ���� �޺κ��� ���ڵ� �� �ڿ������� ��谪���� ���� ��� ã��
// 3. �������� �� ���� �ڸ��� �ٲ��ְ� �޺κ��� ���ڵ��� ������������ ����
#include <bits/stdc++.h>

using namespace std;

vector<int> v;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    bool isExist = false;

    for (int i = 0; i < N; i++) cin >> v[i];

    for (int i = N - 1; i >= 1; i--) {
        if (v[i] < v[i - 1]) {
            isExist = true;

            for (int j = N - 1; j >= i; j--) {
                if (v[i - 1] > v[j]) {
                    int temp = v[i - 1];
                    v[i - 1] = v[j];
                    v[j] = temp;
                    sort(v.begin() + i, v.end(), cmp);
                    break;
                }
            }

            if (isExist) break;
        }     
    }

    if (isExist) {
        for (int i = 0; i < N; i++) cout << v[i] << " ";
    }
    else {
        cout << "-1";
    }    

    return 0;
}

/* vector<int> a;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (prev_permutation(a.begin(), a.end())) {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
    }
    else cout << "-1";
    return 0;
} */