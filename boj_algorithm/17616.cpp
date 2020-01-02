#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
vector<int> road[100005];
vector<int> reRoad[100005];
bool check[100005];
int main() {
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		reRoad[b].push_back(a);
	}
	queue<int> que;
	que.push(x);
	int loser = 0;
	check[x] = true;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto k : road[now]) {
			if (check[k]) {
				continue;
			}
			que.push(k);
			check[k] = true;
			loser++;
		}
	}
	memset(check, 0, sizeof(bool) * 100005);
	int winner = 0;
	check[x] = true;
	que.push(x);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto k : reRoad[now]) {
			if (check[k]) {
				continue;
			}
			que.push(k);
			check[k] = true;
			winner++;
		}
	}
	cout << winner + 1 << " " << n - loser << "\n";
	return 0;
}