#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
long long arr[100005];
vector< pair<int, long long> > road[100005];
int parent[100005][20];
long long cost[100005][20];
bool check[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		road[b].push_back({ a,c });
	}
	queue<int> que;
	que.push(1);
	check[1] = true;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 1; i < 20; i++) {
			parent[now][i] = parent[parent[now][i - 1]][i - 1];
			cost[now][i] = cost[now][i - 1] + cost[parent[now][i - 1]][i - 1];
		}
		for (auto k : road[now]) {
			if (check[k.first]) {
				continue;
			}
			check[k.first] = true;
			que.push(k.first);
			parent[k.first][0] = now;
			cost[k.first][0] = k.second;
		}
	}
	cout << 1 << "\n";
	for (int i = 2; i <= n; i++) {
		int num = 19;
		int now = i;
		while (num >= 0) {
			if (parent[now][num] != 0 && arr[i] >= cost[now][num]) {
				arr[i] -= cost[now][num];
				now = parent[now][num];
			}
			num--;
		}
		cout << now << "\n";
	}
	return 0;
}