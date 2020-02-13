#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int not_node = 10002;
vector<int> road[20005];
stack<int> sta;
int visit[20005];
int index = 1;
int scc[20005];
int visit_num = 1;
int not_func(int a) {
	if (a < 0) {
		return a * -1;
	}
	else {
		return not_node + a;
	}
}
int func(int a) {
	if (a > 0) {
		return a;
	}
	else {
		return not_node + a * -1;
	}
}
int scc_func(int num) {
	if (visit[num] > 0) {
		return 0;
	}
	visit[num] = visit_num++;
	sta.push(num);
	int temp = visit[num];

	for (auto k : road[num]) {
		if (visit[k] == 0) {
			temp = min(temp, scc_func(k));
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
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		road[not_func(a)].push_back(func(b));
		road[not_func(b)].push_back(func(a));
	}
	for (int i = 1; i <= n; i++) {
		scc_func(i);
		scc_func(i + not_node);
	}

	bool ans = true;
	for (int i = 1; i <= n; i++) {
		if (scc[i] == scc[i + not_node]) {
			ans = false;
			break;
		}
	}
	if (ans) {
		cout << "^_^" << endl;
	}
	else {
		cout << "OTL" << endl;
	}
	return 0;
}