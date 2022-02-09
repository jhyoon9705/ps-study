using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <int> v;
	int n, l;
	int tape = 0;
	
	cin >> n >> l;
	while (n--) {
		int input = 0;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < (int)v.size() - 1; i++) {
		for (int j = 1; j < (int)v.size(); j++) {
			if ((v[j] + 0.5) - (v[i] - 0.5) >= l) {
				tape++;
				i = j;
				j++;

			}
		}
	}
	tape++;
	cout << tape << endl;

	return 0;
}
