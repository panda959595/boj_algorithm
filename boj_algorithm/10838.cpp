#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int parent[100005];
int color[100005];
int check[100005];
int n, k;
int r, a, b, c;
int getlca(int x, int y, int k) {
	if (x == y)return x;
	int cnt = 0;
	while (x&&cnt < 1000) {
		check[x] = k;
		x = parent[x];
		cnt++;
	}
	cnt = 0;
	while (y&&cnt < 1000) {
		if (check[y] == k)
			return y;
		y = parent[y];
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> r >> a >> b;
		if (r == 1) {
			cin >> c;
			int p = getlca(a, b, k - i + 1);
			while (a != p) {
				color[a] = c;
				a = parent[a];
			}
			while (b != p) {
				color[b] = c;
				b = parent[b];
			}
		}
		else if (r == 2) {
			parent[a] = b;
		}
		else {
			int p = getlca(a, b, k - i + 1);
			set<int> s;
			while (a != p) {
				s.insert(color[a]);
				a = parent[a];
			}
			while (b != p) {
				s.insert(color[b]);
				b = parent[b];
			}
			cout << s.size() << "\n";
		}
	}
	return 0;
}