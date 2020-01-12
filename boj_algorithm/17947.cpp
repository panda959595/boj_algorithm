#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int remain[400005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	int a, b;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		remain[i] = 4 * n / k;
	}
	for (int i = 1; i <= (4 * n) % k; i++) {
		remain[i]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		remain[a % k]--;
		remain[b % k]--;
	}
	cin >> a >> b;
	int ky = abs((a % k) - (b % k));
	remain[a % k]--;
	remain[b % k]--;
	int right = k - 1;
	int left = right - ky - 1;
	int ans = 0;
	while (right > ky&& left >= 0) {
		if (left > right - ky - 1) {
			left = right - ky - 1;
		}
		while (remain[right] > 0 && left >= 0) {
			if (remain[left] > 0) {
				int temp = min(remain[left], remain[right]);
				ans += temp;
				remain[left] -= temp;
				remain[right] -= temp;
			}
			else {
				left--;
			}
		}
		right--;
	}
	ans = min(ans, m - 1);
	cout << ans << "\n";
	return 0;
}