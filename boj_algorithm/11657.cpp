#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000000;
vector< pair<int,int> > road[505];
int n, m;
int dis[505];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	dis[1] = 0;
	for (int t = 0; t < n - 1; t++) {
		for (int i = 1; i <= n; i++) {
			for (auto k : road[i]) {
				if (dis[i] != INF && dis[i] + k.second < dis[k.first]) {
					dis[k.first] = dis[i] + k.second;
				}
			}
		}
	}
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		for (auto k : road[i]) {
			if (dis[i] != INF && dis[i] + k.second < dis[k.first]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (flag) {
		cout << "-1" << endl;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dis[i] == INF) {
				dis[i] = -1;
			}
			cout << dis[i] << endl;
		}
	}
	return 0;
}