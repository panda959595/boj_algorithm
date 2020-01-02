#include <iostream>
#include <cmath>
using namespace std;
int arr[1005];
int dp[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
		dp[i + 1] = dp[i] + abs(arr[i + 1] - arr[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a] << "\n";
	}
	return 0;
}