#include <bits/stdc++.h>
using namespace std;

int n;
double arr[10002], input, ret;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	double b = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > b * arr[i]) b = arr[i];
		else b *= arr[i];
		ret = max(b, ret);
	}
	printf("%.3lf", ret + 0.00001);
	return 0;
}