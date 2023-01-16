#include <bits/stdc++.h>
using namespace std;

int arr[1000004], ret[1000004];
stack<int> st;
int n, input;

int main() {
	cin >> n;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		while (st.size() && arr[st.top()] < arr[i]) {
			ret[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < n; i++) cout << ret[i] << " ";
	
	return 0;
}