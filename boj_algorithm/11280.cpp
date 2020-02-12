#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define minus_node 10001
vector<int> road[20010];
vector<int> re_road[20010];
vector<int> scc[20010];
stack<int> sta1;
stack<int> sta2;
int check[20010];
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
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[not_func(a)].push_back(func(b));
		re_road[func(b)].push_back(not_func(a));
		road[not_func(b)].push_back(func(a));
		re_road[func(a)].push_back(not_func(b));
	}
	for (int i = 1; i <= n; i++) {
		check[i] = check[i + minus_node] = -1;
	}
	int index = 1;
	for (int i = 1; i <= n; i++) {
		if (check[i] > 0) {
			continue;
		}
		check[i] = 0;
		sta1.push(i);
		while (!sta1.empty()) {
			int now = sta1.top();
			for (auto k : road[now]) {
				if (check[k] == -1) {
					sta1.push(k);
					check[k] = 0;
					break;
				}
			}
			if (now == sta1.top()) {
				sta1.pop();
				sta2.push(now);
			}
		}
		while (!sta2.empty()) {
			int temp = sta2.top();
			sta2.pop();
			if (check[temp] > 0) {
				continue;
			}
			sta1.push(temp);
			check[temp] = index;
			scc[index].push_back(i);
			while (!sta1.empty()) {
				int now = sta1.top();
				for (auto k : re_road[now]) {
					if (check[k] == 0) {
						sta1.push(k);
						check[k] = index;
						scc[index].push_back(k);
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
	for (int i = 1 + minus_node; i <= n + minus_node; i++) {
		if (check[i] > 0) {
			continue;
		}
		check[i] = 0;
		sta1.push(i);
		while (!sta1.empty()) {
			int now = sta1.top();
			for (auto k : road[now]) {
				if (check[k] == -1) {
					sta1.push(k);
					check[k] = 0;
					break;
				}
			}
			if (now == sta1.top()) {
				sta1.pop();
				sta2.push(now);
			}
		}
		while (!sta2.empty()) {
			int temp = sta2.top();
			sta2.pop();
			if (check[temp] > 0) {
				continue;
			}
			sta1.push(temp);
			check[temp] = index;
			scc[index].push_back(i);
			while (!sta1.empty()) {
				int now = sta1.top();
				for (auto k : re_road[now]) {
					if (check[k] == 0) {
						sta1.push(k);
						check[k] = index;
						scc[index].push_back(k);
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
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (check[i] == check[i + minus_node]) {
			ans = 0;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}