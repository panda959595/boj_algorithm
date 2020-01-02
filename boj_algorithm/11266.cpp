#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int n, m;
vector<int> road[10005];
vector<int> ans;
stack<int> sta;
vector<int> check;
int mv;
int dfs(int num, bool flag) {
	bool ans_flag = false;
	check[num] = ++mv;
	int ret = check[num];
	int child = 0;
	for (int i = 0; i < road[num].size(); i++) {
		if (check[road[num][i]] == 0) {
			child++;
			int temp = dfs(road[num][i], false);
			if (!flag&&temp >= check[num]) {
				ans_flag = true;
			}
			ret = min(ret, temp);
		}
		else {
			ret = min(ret, check[road[num][i]]);
		}
	}
	if (flag&&child > 1) {
		ans_flag = true;
	}
	if (ans_flag) {
		ans.push_back(num);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		check.push_back(0);
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			dfs(i, true);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}