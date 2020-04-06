#include <iostream>
#include <vector>
using namespace std;
int arr[55][3];
vector<int> road[120];
bool func(int u, int v) {
	int temp = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[u][i] < arr[v][i]) {
			return false;
		}
		if (arr[u][i] == arr[v][i]) {
			temp++;
		}
	}
	if (temp == 3 && u > v) {
		return false;
	}
	return true;
}
int predator[120];
int prey[55];
bool check[120];
bool matching(int num) {
	check[num] = true;
	for (auto k : road[num]) {
		if (prey[k] == -1 || !check[prey[k]] && matching(prey[k])) {
			prey[k] = num;
			predator[num] = k;
			return true;
		}
	}
	return false;
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (func(i, j)) {
				road[i].push_back(j);
				road[i + 55].push_back(j);
			}
		}
		prey[i] = -1;
	}
	int ans = n;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < n; i++) {
			check[i] = check[i + 55] = false;
		}
		if (matching(i)) {
			ans--;
		}
		for (int i = 0; i < n; i++) {
			check[i] = check[i + 55] = false;
		}
		if (matching(i + 55)) {
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}