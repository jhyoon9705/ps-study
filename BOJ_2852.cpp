#include <bits/stdc++.h>
using namespace std;

int n;
int team;
string timer;
vector<pair<int, int>> v;
int timeA, timeB;
int scoreA, scoreB;

int toSec(string s) {
	int MM = atoi(s.substr(0, s.find(':')).c_str());
	int SS = atoi(s.substr(s.find(':') + 1).c_str());
	return MM * 60 + SS;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> team >> timer;
		v.push_back({ team, toSec(timer) });
	}

	for (int i = 0; i < n ; i++) {
		if (v[i].first == 1) scoreA++;
		else scoreB++;
		if (n == 1) {
			if (v[0].first == 1) timeA = 2880 - v[0].second;
			else timeB = 2880 - v[0].second;
			break;
		}
		if (scoreA > scoreB) {
			if (i == n - 1) timeA += 2880 - v[i].second;
			else timeA += v[i + 1].second - v[i].second;
		}
		else if (scoreA < scoreB) {
			if (i == n - 1) timeB += 2880 - v[i].second;
			else timeB += v[i + 1].second - v[i].second;
		}
	}

	string aMM = to_string(timeA / 60);
	string bMM = to_string(timeB / 60);
	string aSS = to_string(timeA % 60);
	string bSS = to_string(timeB % 60);

	if (aMM.size() == 1) aMM = '0' + aMM;
	if (bMM.size() == 1) bMM = '0' + bMM;
	if (aSS.size() == 1) aSS = '0' + aSS;
	if (bSS.size() == 1) bSS = '0' + bSS;
	
	cout << aMM + ":" + aSS << '\n';
	cout << bMM + ":" + bSS << '\n';

	return 0;
}