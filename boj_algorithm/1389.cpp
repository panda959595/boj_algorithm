#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> road[105];
int cost[105][105];
bool check[105];
vector< pair<int, int> > ans;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		queue<int> que;
		que.push(i);
		for (int i = 1; i <= n; i++) {
			check[i] = false;
		}
		check[i] = true;
		cost[i][i] = 0;
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			for (auto next : road[now]) {
				if (check[next]) {
					continue;
				}
				que.push(next);
				check[next] = true;
				cost[i][next] = cost[i][now] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			temp += cost[i][j];
		}
		ans.push_back({ temp, i });
	}
	sort(ans.begin(), ans.end());
	cout << ans[0].second << endl;
	return 0;
}