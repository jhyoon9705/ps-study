// 1. 배열의 뒤부터 2개씩 비교하면서 앞의 숫자가 더 큰 경우 찾기
// 2. 앞 숫자가 더 큰 부분을 경계로 뒷부분의 숫자들 중 뒤에서부터 경계값보다 작은 경우 찾기
// 3. 위에서의 두 수의 자리를 바꿔주고 뒷부분의 숫자들을 내림차순으로 정렬
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