#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int num, value, temp;
	long long sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> num;

	while (num--) {
		cin >> value;
		pq.push(value);
	}

	while (pq.size() > 1) {
		temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		sum += temp;
		pq.push(temp);
	}

	cout << sum;

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	int n, temp;
//	int sum = 0;
//	int tempsum = 0;
//	vector <int> v, t;
//	
//	cin >> n;
//
//	if (n == 1) {
//		cin >> temp;
//		cout << 0;
//		return 0;
//	}
//	else {
//		v.reserve(n);
//		t.reserve(n - 1);
//
//		while (n--) {
//			cin >> temp;
//			v.push_back(temp);
//		}
//
//		sort(v.begin(), v.end());
//		t.push_back(v[0] + v[1]);
//
//		for (int i = 2; i < (int)v.size(); i++) {
//			tempsum = t[i - 2] + v[i];
//			t.push_back(tempsum);
//
//		}
//
//		for (int j = 0; j < (int)t.size(); j++) {
//			sum += t[j];
//		}
//
//		cout << sum;
//	}
//
//	return 0;
//}
