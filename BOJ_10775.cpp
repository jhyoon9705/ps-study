#include <bits/stdc++.h>

using namespace std; 

int G,P,g; 
int parent[100001]; 

int find(int x) { 
	if(x==parent[x]) return x; 
	return parent[x] = find(parent[x]); 
} 

int main() {
	int counter = 0;
	cin >> G >> P;

	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}

	for(int i = 1; i<= P; i++) { 
		cin >>g; 

		if(!find(g)) break; 
		else { 
			counter++; 
			parent[find(g)]=find(find(g)-1); 
		} 
	} 

	cout << counter; 
}



// 시간 초과 code
/*#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int G, P;
	cin >> G;
	cin >> P;

	vector<int> planes;
	vector<int> gates;
	int counter = 0;

	for (int i = 0; i < P; i++) {
		int input;
		cin >> input;
		planes.push_back(input);
	}

	for (int i = 0; i < G; i++) {
		gates.push_back(0);
	}

	int dockingPlane;
	bool canDocking = true;

	while (canDocking) {
		dockingPlane = planes[0];
		for (int j = dockingPlane - 1; j >= 0; j--) {
			if (gates[j] == 0) {
				gates[j] = 1;
				counter++;
				planes.erase(planes.begin());
				break;
			}
			if (j == 0) {
				canDocking = false;
			}
		}
	}

	cout << counter << endl;

}*/