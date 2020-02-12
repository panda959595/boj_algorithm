#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define minus_node 10005
vector<int> road[20010];
vector<int> scc[20010];
stack<int> sta;
int check[20010];
int visit[20010];
bool finish[20010];
int visit_num = 1;
int index = 1;
int not_func(int a) {
	if (a < 0) {
		return a * -1;
	}
	else {
		return minus_node + a;
	}
}
int func(int a) {
	if (a > 0) {
		return a;
	}
	else {
		return minus_node + a * -1;
	}
}
int dfs(int num) {
	if (visit[num] > 0) {
		return 0;
	}
	visit[num] = visit_num++;
	sta.push(num);

	int result = visit[num];
	for (auto k : road[num]) {
		if (visit[k] == 0) {
			result = min(result, dfs(k));
		}
		else if (!finish[k]) {
			result = min(result, visit[k]);
		}
	}

	if (result == visit[num]) {
		while (1) {
			int now = sta.top();
			sta.pop();
			scc[index].push_back(now);
			check[now] = index;
			finish[now] = true;
			if (num == now) {
				break;
			}
		}
		index++;
	}
	return result;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[not_func(a)].push_back(func(b));
		road[not_func(b)].push_back(func(a));
	}
	for (int i = 1; i <= n; i++) {
		check[i] = check[i + minus_node] = -1;
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
		dfs(i + minus_node);
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == check[i + minus_node]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1 << endl;
	for (int i = 1; i <= n; i++) {
		if (check[i] < check[i + minus_node]) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
	return 0;
}