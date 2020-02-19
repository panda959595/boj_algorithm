#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int not_node = 100002;
vector<int> swit[100005];
vector<int> road[200005];
int now[200005];
int n, m;
stack<int> sta;
int scc[200005];
int index;
int visit[200005];
int visit_num = 1;
int dfs(int num) {
	if (visit[num] > 0) {
		return 0;
	}
	visit[num] = visit_num++;
	sta.push(num);

	int temp = visit[num];
	for (auto k : road[num]) {
		if (visit[k] == 0) {
			temp = min(temp, dfs(k));
		}
		if (scc[k] == 0) {
			temp = min(temp, visit[k]);
		}
	}
	if (temp == visit[num]) {
		while (1) {
			int now = sta.top();
			sta.pop();
			scc[now] = index;
			if (now == num) {
				break;
			}
		}
		index++;
	}
	return temp;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> now[i];
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		while (k--) {
			int temp;
			cin >> temp;
			swit[temp].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (now[i] == 1) {
			road[swit[i][0] + not_node].push_back(swit[i][1] + not_node);
			road[swit[i][1]].push_back(swit[i][0]);
			road[swit[i][0]].push_back(swit[i][1]);
			road[swit[i][1] + not_node].push_back(swit[i][0] + not_node);
		}
		else {
			road[swit[i][0] + not_node].push_back(swit[i][1]);
			road[swit[i][1] + not_node].push_back(swit[i][0]);
			road[swit[i][0]].push_back(swit[i][1] + not_node);
			road[swit[i][1]].push_back(swit[i][0] + not_node);
		}
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
		dfs(i + not_node);
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (scc[i] == scc[i + not_node]) {
			ans = 0;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}