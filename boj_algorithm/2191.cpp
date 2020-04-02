#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
pair<double, double> mouse[105];
pair<double, double> hole[105];
vector<int> road[105];
double n, m, s, t;
bool road_check(int u, int v) {
	if (pow(s * t, 2) >= pow(mouse[u].first - hole[v].first, 2) + pow(mouse[u].second - hole[v].second, 2)) {
		return true;
	}
	else {
		return false;
	}
}
int ans;
bool check[210];
int mouse_check[105];
int hole_check[105];
bool func(int n) {
	check[n] = true;
	for (auto k : road[n]) {
		if (hole_check[k] == 0 || (!check[hole_check[k]] && func(hole_check[k]))) {
			mouse_check[n] = k;
			hole_check[k] = n;
			return true;
		}
	}
	return false;
}
int main() {
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++) {
		cin >> mouse[i].first >> mouse[i].second;
	}
	for (int i = 1; i <= m; i++) {
		cin >> hole[i].first >> hole[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (road_check(i, j)) {
				road[i].push_back(j);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			check[j] = false;
		}
		if (func(i)) {
			ans++;
		}
	}
	cout << n - ans << endl;
	return 0;
}