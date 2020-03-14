#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<int> road[10010];//R <=5000, B >5000
const int not_node = 5005;
int func(int num, char ch) {
	if (ch == 'R') {
		return num;
	}
	else {
		return num + not_node;
	}
}
int not_func(int num, char ch) {
	if (ch == 'B') {
		return num;
	}
	else {
		return num + not_node;
	}
}
int scc[10010];
int index = 1;
int check[10010];
int check_num;
stack<int> sta;
int make_scc(int num) {
	if (check[num] != 0) {
		return 0;
	}
	check[num] = ++check_num;
	sta.push(num);

	int ret = check[num];
	for (auto k : road[num]) {
		if (check[k] == 0) {
			ret = min(ret, make_scc(k));
		}
		if (scc[k] == 0) {
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
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		char A, B, C;
		cin >> a >> A >> b >> B >> c >> C;
		road[not_func(a, A)].push_back(func(b, B));
		road[not_func(a, A)].push_back(func(c, C));
		road[not_func(b, B)].push_back(func(a, A));
		road[not_func(b, B)].push_back(func(c, C));
		road[not_func(c, C)].push_back(func(a, A));
		road[not_func(c, C)].push_back(func(b, B));
	}
	for (int i = 1; i <= k; i++) {
		make_scc(i);
		make_scc(i + not_node);
	}
	for (int i = 1; i <= k; i++) {
		if (scc[i] == scc[i + not_node]) {
			cout << -1 << "\n";
			return 0;
		}
	}
	for (int i = 1; i <= k; i++) {
		if (scc[i] < scc[i + not_node]) {
			cout << 'R';
		}
		else {
			cout << 'B';
		}
	}
	return 0;
}