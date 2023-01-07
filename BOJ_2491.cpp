#include <bits/stdc++.h>

using namespace std;

int arr[100000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int newLen = 1;
	int len = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) len++;
		else len = 1;
		newLen = max(newLen, len);
	}

	len = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] <= arr[i - 1]) len++;
		else len = 1;
		newLen = max(newLen, len);
	}
	cout << newLen;
}

// ===== failed code =====
// #include <bits/stdc++.h>
// 
// #define INC true;
// #define DEC false;
// 
// using namespace std;
// 
// int main() {
// 	int n, number, popped, compare, result;
// 	int increase = 1;
// 	int decrease = 1;
// 	bool checker = true;
// 	vector<int> v, candidates;
// 
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		cin >> number;
// 		v.push_back(number);
// 	}
// 
// 	if (n == 1) {
// 		cout << 1;
// 		return 0;
// 	}
// 
// 	while ((int)v.size() >= 2) {
// 		popped = v[0];
// 		compare = v[1];
// 		v.erase(v.begin());
// 
// 		if (popped < compare) {
// 			if (checker == false) {
// 				candidates.push_back(decrease);
// 				decrease = 1;
// 			}
// 
// 			increase++;
// 			checker = INC;
// 		}
// 		else if(popped == compare) {
// 			increase++;
// 			decrease++;
// 		}
// 		else {
// 			if (checker == true) {
// 				candidates.push_back(increase);
// 				increase = 1;
// 			}
// 			
// 			decrease++;
// 			checker = DEC;
// 		}
// 		
// 	}
// 	candidates.push_back(max(increase, decrease));
// 	sort(candidates.begin(), candidates.end());
// 
// 	result = candidates.back();
// 	cout << result;
// }

