#include <bits/stdc++.h>
using namespace std;

int N;
int RotateNum;
int result;
deque<int> gear[5];

void Rotate(int visited[5], int num, int dir) {
    visited[num] = 1;

    if (num - 1 >= 1 && gear[num][6] != gear[num - 1][2] && visited[num - 1] == 0) {
        if (dir == 1) {
            Rotate(visited, num - 1, -1);
        }
        else {
            Rotate(visited, num - 1, 1);
        }
    }

    if (num + 1 <= 4 && gear[num][2] != gear[num + 1][6] && visited[num + 1] == 0) {
        if (dir == 1) {
            Rotate(visited, num + 1, -1);
        }
        else {
            Rotate(visited, num + 1, 1);
        }
    }

    if (dir == 1) {
        int temp = gear[num].back();
        gear[num].pop_back();
        gear[num].push_front(temp);
    }
    else {
        int temp = gear[num].front();
        gear[num].pop_front();
        gear[num].push_back(temp);
    }
}

int main(void) {
    for (int i = 1; i <= 4; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < input.size(); j++) {
            gear[i].push_back(input[j] - '0');
        }
    }

    cin >> RotateNum;

    while (RotateNum--) {
        int visited[5] = { 0 };
        int num, direction;
        cin >> num >> direction;
        Rotate(visited, num, direction);
    }

    for (int i = 1; i <= 4; i++) {
        if (gear[i][0] == 1) {
            if (i == 1) result += 1;
            else if (i == 2) result += 2;
            else if (i == 3) result += 4;
            else if (i == 4) result += 8;
        }
    }

    cout << result;

    return 0;
}
