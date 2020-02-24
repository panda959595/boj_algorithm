#include <iostream>
using namespace std;
const int ttemp = 1048576;
int f[200005][20];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q, x;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> f[i][0];
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= m; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
	cin >> q;
	while (q--) {
		cin >> x >> n;
		int temp = 20;
		int num = ttemp;
		while (num > 0) {
			if (num <= x) {
				n = f[n][temp];
				x -= num;
			}
			num /= 2;
			temp--;
		}
		cout << n << "\n";
	}
	return 0;
}