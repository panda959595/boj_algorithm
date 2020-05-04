#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int S = 20003;
const int T = 20004;
struct road_stru {
	int detiny;
	int cost;
	int flow;
};
char dosi[105][105];
vector<road_stru> road[20005];
pair<int,int> pre[20005];
bool check[20005];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dosi[i][j];
		}
	}
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dosi[i][j] == '#') {
				continue;
			}
			road[i * m + j].push_back({ i * m + j + 10000, 1,0 });
			road[i * m + j + 10000].push_back({ i * m + j ,0,0 });
			if (dosi[i][j] == 'K') {
				road[i * m + j][road[i * m + j].size() - 1].cost += 100000;
				road[S].push_back({ i * m + j ,100000,0 });
				road[i * m + j].push_back({ S ,0,0 });
			}
			if (dosi[i][j] == 'H') {
				road[i * m + j][road[i * m + j].size() - 1].cost += 100000;
				road[i * m + j + 10000].push_back({ T ,100000,0 });
				road[T].push_back({ i * m + j + 10000 ,0,0 });
			}
			for (int k = 0; k < 2; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 && x < n && y >= 0 && y < m && dosi[x][y] != '#') {
					if (dosi[i][j] == 'K' && dosi[x][y] == 'H') {
						flag = true;
					}
					road[i * m + j + 10000].push_back({ x * m + y ,1,0 });
					road[x * m + y].push_back({ i * m + j + 10000 ,1,0 });
				}
			}
		}
	}
	int ans = 0;
	if (flag) {
		cout << -1 << endl;
		return 0;
	}
	while (1) {
		queue<int> que;
		for (int i = 0; i < n * m; i++) {
			pre[i].first = -1;
			check[i] = false;
			check[i + 10000] = false;
		}
		pre[S].first = pre[T].first = -1;
		check[S] = check[T] = false;
		que.push(S);
		check[S] = true;
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			if (now == T) {
				break;
			}
			for (int i = 0; i < road[now].size(); i++) {
				if (!check[road[now][i].detiny] && road[now][i].cost - road[now][i].flow > 0) {
					check[road[now][i].detiny] = true;
					pre[road[now][i].detiny] = make_pair(now, i);
					que.push(road[now][i].detiny);
				}
			}
		}
		if (pre[T].first == -1) {
			break;
		}
		int temp = n * m + 10000;
		for (int i = T; i != S; i = pre[i].first) {
			temp = min(temp, road[pre[i].first][pre[i].second].cost - road[pre[i].first][pre[i].second].flow);
		}
		ans += temp;
		for (int i = T; i != S; i = pre[i].first) {
			road[pre[i].first][pre[i].second].flow += temp;
		}
	}
	cout << ans << endl;
	return 0;
}