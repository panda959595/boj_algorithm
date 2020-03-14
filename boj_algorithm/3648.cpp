#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int not_node = 1002;
vector<int> road[2010];
int func(int num) {
	if (num > 0) {
		return num;
	}
	else {
		return num * -1 + not_node;
	}
}
int not_func(int num) {
	if (num > 0) {
		return num + not_node;
	}
	else {
		return num * -1;
	}
}
int scc[2010];
int check[2010];
int check_num;
int index;
stack<int> sta;
int make_scc(int num) {
	if (check[num] != -1) {
		return 1;
	}
	check[num] = check_num++;
	sta.push(num);

	int ret = check[num];
	for (auto k : road[num]) {
		if (check[k] == -1) {
			ret = min(ret, make_scc(k));
		}
		if (scc[k] == -1) {
			ret = min(ret, check[k]);
		}
	}
	if (ret == check[num]) {
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
	return ret;
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++) {
			road[i].clear();
			scc[i] = -1;
			check[i] = -1;
			road[i + not_node].clear();
			scc[i + not_node] = -1;
			check[i + not_node] = -1;
			check_num = 1;
			index = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			road[not_func(a)].push_back(func(b));
			road[not_func(b)].push_back(func(a));
		}
		road[1 + not_node].push_back(1);
		for (int i = 1; i <= n; i++) {
			make_scc(i);
			make_scc(i + not_node);
		}
		bool ans = true;
		for (int i = 1; i <= n; i++) {
			if (scc[i] == scc[i + not_node]) {
				ans = false;
				break;
			}
		}
		if (ans) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}