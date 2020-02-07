#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> road[405];
int cost[405][405];
int flow[405][405];
int pre[405];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
		cost[a][b] = 1;
	}
	int ans = 0;
	while (1) {
		for (int i = 1; i <= n; i++) {
			pre[i] = -1;
		}
		queue<int> que;
		que.push(1);
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			if (now == 2) {
				break;
			}
			for (auto k : road[now]) {
				if (pre[k] == -1 && cost[now][k] - flow[now][k] > 0) {
					pre[k] = now;
					que.push(k);
				}
			}
		}
		if (pre[2] == -1) {
			break;
		}
		int f = 400000;
		for (int i = 2; i != 1; i = pre[i]) {
			f = min(f, cost[pre[i]][i] - flow[pre[i]][i]);
		}
		for (int i = 2; i != 1; i = pre[i]) {
			flow[pre[i]][i] += f;
			flow[i][pre[i]] -= f;
		}
		ans += f;
	}
	cout << ans << endl;
	return 0;
}