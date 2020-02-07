#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> road[100005];
vector<int> re_road[100005];
int group[100005];
int index;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < 100005; i++) {
			road[i].clear();
			re_road[i].clear();
			group[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (a == b) {
				continue;
			}
			road[a].push_back(b);
			re_road[b].push_back(a);
		}
		index = 1;
		for (int i = 0; i < n; i++) {
			if (group[i] != -1) {
				continue;
			}
			stack<int> sta1;
			stack<int> sta2;
			sta1.push(i);
			group[i] = 0;
			while (!sta1.empty()) {
				int now = sta1.top();
				for (auto k : road[now]) {
					if (group[k] == -1) {
						sta1.push(k);
						group[k] = 0;
						break;
					}
				}
				if (sta1.top() == now) {
					sta1.pop();
					sta2.push(now);
				}
			}
			while (!sta2.empty()) {
				int temp = sta2.top();
				sta2.pop();
				if (group[temp] != 0) {
					continue;
				}
				sta1.push(temp);
				int check = 0;
				while (!sta1.empty()) {
					int now = sta1.top();
					group[now] = index;
					check++;
					for (auto k : re_road[now]) {
						if (group[k] == 0) {
							sta1.push(k);
							break;
						}
					}
					if (sta1.top() == now) {
						sta1.pop();
					}
				}
				index++;
			}
		}
		int ans = -2;
		bool check[100005];
		for (int i = 1; i < index; i++) {
			check[i] = true;
		}
		for (int i = 0; i < n; i++) {
			for (auto k : road[i]) {
				if (group[i] != group[k]) {
					check[group[k]] = false;
				}
			}
		}
		for (int i = 1; i < index; i++) {
			if (check[i]) {
				if (ans == -2) {
					ans = i;
				}
				else {
					ans = -1;
				}
			}
		}
		if (ans < 0) {
			cout << "Confused" << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (group[i] == ans) {
					cout << i << endl;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
