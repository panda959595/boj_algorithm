#include <iostream>
#include <queue>
using namespace std;
int arr[505][505];
long long dp[505][505];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
long long func(int x, int y) {
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	long long ret = 0;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && arr[x][y] < arr[x + dx[i]][y + dy[i]]) {
			ret += func(x + dx[i], y + dy[i]);
		}
	}
	return dp[x][y] = ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 1;
	func(n - 1, m - 1);
	cout << dp[n - 1][m - 1] << endl;
	return 0;
}