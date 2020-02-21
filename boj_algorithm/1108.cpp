#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
vector<int> road[5000];
int num[5000];
int pre[5000];
int visit[5000];
stack<int> sta;
int check[5000];
int index = 1;
int visit_num = 1;
long long score[5000];
map<string, int> ma;
int map_index = 1;
int map_func(string str) {
	if (ma[str] != 0) {
		return ma[str];
	}
	pre[map_index] = 0;
	return ma[str] = map_index++;
}
int scc_func(int num) {
	if (visit[num] > 0) {
		return 0;
	}
	visit[num] = visit_num++;
	sta.push(num);

	int ret = visit[num];
	for (auto k : road[num]) {
		if (visit[k] == 0) {
			ret = min(ret, scc_func(k));
		}
		if (check[k] == 0) {
			ret = min(ret, visit[k]);
		}
	}
	if (ret == visit[num]) {
		while (1) {
			int temp = sta.top();
			sta.pop();
			check[temp] = index;
			if (temp == num) {
				break;
			}
		}
		index++;
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 5000; i++) {
		pre[i] = -1;
		score[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		string str1;
		cin >> str1;
		int temp;
		cin >> temp;
		int temp1;
		temp1 = map_func(str1);
		pre[temp1] = temp;
		while (temp--) {
			string str2;
			cin >> str2;
			int temp2 = map_func(str2);
			road[temp2].push_back(temp1);
		}
	}
	queue<int> que;
	for (int i = 1; i < map_index; i++) {
		scc_func(i);
		if (pre[i] == 0) {
			que.push(i);
		}
	}
	for (int i = 1; i < map_index; i++) {
		for (auto k : road[i]) {
			if (check[i] == check[k]) {
				pre[k]--;
				if (pre[k] == 0) {
					que.push(k);
				}
			}
		}
	}
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto k : road[now]) {
			if (check[k] == check[now]) {
				continue;
			}
			score[k] += score[now];
			pre[k]--;
			if (pre[k] == 0) {
				que.push(k);
			}
		}
	}
	string str;
	cin >> str;
	cout << score[map_func(str)] << endl;
	return 0;
}