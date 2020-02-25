#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int n, m;
vector< pair<int,int> > road[1505];
int road_num[1505][1505];
int ans[5005];
int cost[1505];
bool check[1505];
vector<int> pre[1505];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b, c });
		road_num[a][b] = i;
	}
	priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++) {
			pre[i].clear();
			cost[i] = 1000000000;
			check[i] = false;
		}
		pq.push({ 0,i });
		while (!pq.empty()) {
			pair<int,int> now = pq.top();
			pq.pop();
			if (check[now.second]) {
				continue;
			}
			check[now.second] = true;
			for (auto k : road[now.second]) {
				if (cost[k.first] < now.first + k.second) {
					continue;
				}
				else if (cost[k.first] == now.first + k.second) {
					pre[k.first].push_back(now.second);
				}
				else {
					pre[k.first].clear();
					pre[k.first].push_back(now.second);
					pq.push({ now.first + k.second , k.first });
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (auto k : pre[i]) {
				ans[road_num[k][i]]++;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}