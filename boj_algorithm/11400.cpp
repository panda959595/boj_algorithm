#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> road[100005];
vector< pair<int, int> > ans;
int check[100005];
int mv;
int func(int now, int pre) {
	check[now] = ++mv;
	int ret = check[now];
	for (int i = 0; i < road[now].size(); i++) {
		if (road[now][i] == pre) {
			continue;
		}
		if (check[road[now][i]] == 0) {
			int temp = func(road[now][i], now);
			if (temp > check[now]) {
				ans.push_back({ min(now,road[now][i]),max(now,road[now][i]) });
			}
			ret = min(ret, temp);
		}
		else {
			ret = min(ret, check[road[now][i]]);
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (check[i] != 0) {
			continue;
		}
		func(i, 0);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}