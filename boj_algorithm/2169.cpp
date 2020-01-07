#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[1005][1005];
int dp[1005][1005];//0up 1left 2right
int dp_temp[2][1005][1005];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < m; i++) {
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = dp[i - 1][j] + arr[i][j];
		}
		dp_temp[0][i][0] = dp[i][0];
		for (int j = 1; j < m; j++) {
			dp_temp[0][i][j] = max(dp[i][j], dp_temp[0][i][j - 1] + arr[i][j]);
		}
		dp_temp[1][i][m - 1] = dp[i][m - 1];
		for (int j = m - 2; j >= 0; j--) {
			dp_temp[1][i][j] = max(dp[i][j], dp_temp[1][i][j + 1] + arr[i][j]);
		}
		for (int j = 0; j < m; j++) {
			dp[i][j] = max(dp_temp[0][i][j], dp_temp[1][i][j]);
		}
	}
	cout << dp[n - 1][m - 1] << endl;
	return 0;
}