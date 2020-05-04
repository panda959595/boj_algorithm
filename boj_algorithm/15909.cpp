#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
long long arr[1310725];
vector<long long> child[1310725][2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < (1 << n); i++) {
		cin >> arr[i];
	}
	queue<int> que;
	for (int i = (1 << (n - 1)); i < (1 << n); i++) {
		que.push(i);
	}
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		if (now == 1) {
			continue;
		}
		for (auto k : child[now][0]) {
			child[now / 2][now % 2].push_back(k + arr[now]);
		}
		for (auto k : child[now][1]) {
			child[now / 2][now % 2].push_back(k + arr[now]);
		}
		child[now / 2][now % 2].push_back(arr[now]);
		sort(child[now / 2][now % 2].begin(), child[now / 2][now % 2].end());
		if (now % 2 == 0) {
			que.push(now / 2);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int a;
		long long b;
		int sibling;
		cin >> a >> b;
		int ans = 0;
		b -= arr[a];
		for (int i = 0; i < 2; i++) {
			int temp = upper_bound(child[a][i].begin(), child[a][i].end(), b) - lower_bound(child[a][i].begin(), child[a][i].end(), b);
			ans += temp;
		}
		if (b == 0) {
			ans++;
		}
		sibling = (a + 1) % 2;
		a /= 2;
		while (a > 0) {
			b -= arr[a];
			int temp = upper_bound(child[a][sibling].begin(), child[a][sibling].end(), b) - lower_bound(child[a][sibling].begin(), child[a][sibling].end(), b);
			ans += temp;
			if (b == 0) {
				ans++;
			}
			sibling = (a + 1) % 2;
			a /= 2;
		}
		cout << ans << "\n";
	}
	return 0;
}