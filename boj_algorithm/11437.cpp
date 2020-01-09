#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int parent[50005][17];
int level[50005];
vector<int> vec[50005];
bool check[50005];
int LCA(int n, int m) {
	if (level[n] != level[m]) {
		if (level[n] < level[m]) {
			int temp = m;
			m = n;
			n = temp;
		}
		//level[n]>level[m]
		for (int i = 16; i >= 0; i--) {
			if (level[parent[n][i]] >= level[m]) {
				n = parent[n][i];
			}
		}
	}
	if (n == m) {
		return n;
	}
	for (int i = 16; i >= 0; i--) {
		if (parent[n][i] != parent[m][i]) {
			n = parent[n][i];
			m = parent[m][i];
		}
	}
	return parent[n][0];
}
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	queue<int> que;
	check[1] = true;
	level[1] = 1;
	que.push(1);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 1; i < 17; i++) {
			parent[now][i] = parent[parent[now][i - 1]][i - 1];
		}
		level[now] = level[parent[now][0]] + 1;
		for (auto k : vec[now]) {
			if (check[k]) {
				continue;
			}
			parent[k][0] = now;
			que.push(k);
			check[k] = true;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << endl;
	}
	return 0;
}