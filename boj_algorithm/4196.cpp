#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<int> road[100005];
vector<int> re_road[100005];
int group[100005];
int index;
int check[100005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		int ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			road[i].clear();
			re_road[i].clear();
			group[i] = -1;
			check[i] = true;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			road[a].push_back(b);
			re_road[b].push_back(a);
		}
		index = 1;
		for (int i = 1; i <= n; i++) {
			if (group[i] == -1) {
				group[i] = 0;
				stack<int> sta1, sta2;
				sta1.push(i);
				while (!sta1.empty()) {
					int now = sta1.top();
					for (auto k : road[now]) {
						if (group[k] < 0) {
							group[k] = 0;
							sta1.push(k);
							break;
						}
					}
					if (now == sta1.top()) {
						sta1.pop();
						sta2.push(now);
					}
				}
				while (!sta2.empty()) {
					int no = sta2.top();
					sta2.pop();
					if (group[no] > 0) {
						continue;
					}
					sta1.push(no);
					while (!sta1.empty()) {
						int now = sta1.top();
						if (group[now] == 0) {
							group[now] = index;
						}
						else {
							sta1.pop();
							continue;
						}
						for (auto k : re_road[now]) {
							if (group[k] == 0) {
								sta1.push(k);
								break;
							}
						}
						if (now == sta1.top()) {
							sta1.pop();
						}
					}
					index++;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (auto k : road[i]) {
				if (group[i] != group[k]) {
					check[group[k]] = false;
				}
			}
		}
		for (int i = 1; i < index; i++) {
			if (check[i]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}