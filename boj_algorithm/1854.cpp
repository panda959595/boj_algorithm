#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct stru {
	int destiny;
	int length;
};
struct node {
	int n;
	int c;
};
vector<stru> road[1005];
priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;
priority_queue<int, vector<int>, less<int> > cost[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a - 1].push_back({ b - 1,c });
	}
	pq.push({ 0, 0 });
	int flag = n;
	cost[0].push(0);
	while (!pq.empty()) {
		pair<int,int> now = pq.top();
		pq.pop();
		for (int i = 0; i < road[now.second].size(); i++) {
			if (cost[road[now.second][i].destiny].size() < k) {
				cost[road[now.second][i].destiny].push(now.first + road[now.second][i].length);
			}
			else if (cost[road[now.second][i].destiny].top()> now.first + road[now.second][i].length) {
				cost[road[now.second][i].destiny].pop();
				cost[road[now.second][i].destiny].push(now.first + road[now.second][i].length);
			}
			else {
				continue;
			}
			pq.push({ now.first + road[now.second][i].length ,road[now.second][i].destiny });
		}
	}
	for (int i = 0; i < n; i++) {
		if (cost[i].size() < k) {
			cout << -1 << "\n";
		}
		else {
			cout << cost[i].top() << "\n";
		}
	}
	return 0;
}