#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int h[51][51];
char map[51][51];
bool check[51][51];
vector<int> vec;
pair<int, int> p;
int ans;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
bool bfs(int s, int e) {
	int temp = ans;
	queue<pair<int, int> > que;
	if (h[p.first][p.second]<s || h[p.first][p.second]>e) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = true;
		}
	}
	que.push(p);
	check[p.first][p.second] = false;
	while (!que.empty()) {
		pair<int, int> now = que.front();
		que.pop();
		if (map[now.first][now.second] == 'K') {
			temp--;
		}
		for (int i = 0; i < 8; i++) {
			pair<int, int> next;
			next.first = now.first + dx[i];
			next.second = now.second + dy[i];
			if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= n) {
				continue;
			}
			if (check[next.first][next.second] && h[next.first][next.second] >= s && h[next.first][next.second] <= e) {
				que.push(next);
				check[next.first][next.second] = false;
			}
		}
	}
	if (temp == 0) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'P') {
				p = { i,j };
			}
			else if (map[i][j] == 'K') {
				ans++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> h[i][j];
			vec.push_back(h[i][j]);
		}
	}
	sort(vec.begin(), vec.end());
	unique(vec.begin(), vec.end());
	int a = 1000000;
	int s, e;
	s = e = 0;
	while (e < vec.size()) {
		if (bfs(vec[s], vec[e])) {
			a = min(a, vec[e] - vec[s]);
			s++;
		}
		else {
			e++;
		}
		if (s > e) {
			e = s;
		}
	}
	cout << a << endl;
	return 0;
}