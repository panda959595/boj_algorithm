#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
vector<int> road[30];
vector<int> re_road[30];
vector<int> scc[30];
bool appear[30];
int scc_index = 0;
void func1() {
	stack<int> sta;
	stack<int> dfs;
	bool check[30];
	for (int i = 0; i < 30; i++) {
		check[i] = false;
	}
	for (int i = 0; i < 30; i++) {
		if (!appear[i] || check[i]) {
			continue;
		}
		check[i] = true;
		dfs.push(i);
		while (!dfs.empty()) {
			int now = dfs.top();
			for (auto k : road[now]) {
				if (check[k]) {
					continue;
				}
				dfs.push(k);
				check[k] = true;
				break;
			}
			if (dfs.top() == now) {
				sta.push(now);
				dfs.pop();
			}
		}
	}
	for (int i = 0; i < 30; i++) {
		check[i] = false;
	}
	while (!sta.empty()) {
		int temp = sta.top();
		sta.pop();
		if (check[temp]) {
			continue;
		}
		dfs.push(temp);
		check[temp] = true;
		while (!dfs.empty()) {
			int now = dfs.top();
			for (auto k : re_road[now]) {
				if (check[k]) {
					continue;
				}
				dfs.push(k);
				check[k] = true;
				break;
			}
			if (dfs.top() == now) {
				dfs.pop();
				scc[scc_index].push_back(now);
			}
		}
		scc_index++;
	}
}
bool bigyo(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}
void func2(int num) {

}
int main() {
	int T;
	while (cin >> T) {
		if (T == 0) {
			break;
		}
		char input[6];
		bool road_check[30][30];
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				road_check[i][j] = false;
			}
			road_check[i][i] = true;
			re_road[i].clear();
			road[i].clear();
			appear[i] = false;
			scc[i].clear();
		}
		scc_index = 0;
		for (int i = 0; i < T; i++) {
			for (int j = 0; j < 6; j++) {
				cin >> input[j];
				appear[input[j] - 'A'] = true;
			}
			for (int j = 0; j < 5; j++) {
				if (road_check[input[5] - 'A'][input[j] - 'A']) {
					continue;
				}
				road[input[5] - 'A'].push_back(input[j] - 'A');
				re_road[input[j] - 'A'].push_back(input[5] - 'A');
				road_check[input[5] - 'A'][input[j] - 'A'] = true;
			}
		}
		func1();
		for (int i = 0; i < scc_index; i++) {
			sort(scc[i].begin(), scc[i].end());
		}
		sort(scc, scc + scc_index, bigyo);
		char c;
		for (int i = 0; i < scc_index; i++) {
			for (auto k : scc[i]) {
				c = 'A';
				c += k;
				cout << c << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}