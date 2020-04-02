#include <iostream>
#include <queue>
using namespace std;
bool check[2005][2005];
pair<int, int> parent[2005][2005];
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
int civil;
pair<int, int> find(pair<int, int> num) {
	if (num == parent[num.first][num.second]) {
		return num;
	}
	else {
		return parent[num.first][num.second] = find(parent[num.first][num.second]);
	}
}
void merge(pair<int, int> a, pair<int, int> b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return;
	}
	parent[b.first][b.second] = a;
	civil--;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = { i,j };
			check[i][j] = false;
		}
	}
	queue<pair<int, int> > que;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		check[a][b] = 1;
		que.push({ a,b });
		civil++;
		for (int j = 0; j < 4; j++) {
			if (a + dx[j] < 1 || a + dx[j] > n || b + dy[j] < 1 || b + dy[j] > n || !check[a + dx[j]][b + dy[j]]) {
				continue;
			}
			merge({ a,b }, { a + dx[j],b + dy[j] });
		}
	}
	int ans = 0;
	while (1) {
		int size = que.size();
		if (civil == 1) {
			break;
		}
		ans++;
		for (int s = 0; s < size; s++) {
			pair<int, int> now = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				pair<int, int> temp;
				temp.first = now.first + dx[i];
				temp.second = now.second + dy[i];
				if (temp.first<1 || temp.first>n || temp.second<1 || temp.second>n) {
					continue;
				}
				if (!check[temp.first][temp.second]) {
					que.push(temp);
					check[temp.first][temp.second] = true;
					parent[temp.first][temp.second] = find(now);
					for (int j = 0; j < 4; j++) {
						pair<int, int> ttemp = { temp.first + dx[j],temp.second + dy[j] };
						if (ttemp.first<1 || ttemp.first>n || ttemp.second<1 || ttemp.second>n || !check[ttemp.first][ttemp.second]) {
							continue;
						}
						merge(temp, ttemp);
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}