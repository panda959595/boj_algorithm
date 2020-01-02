#include <iostream>
using namespace std;
int dp[505][505];
int arr[505];
int sum[505];
int func(int s, int e) {
	if (s == e) {
		return 0;
	}
	if (dp[s][e] != -1) {
		return dp[s][e];
	}
	if (e == s + 1) {
		return dp[s][e] = arr[s] + arr[e];
	}
	int ret = 100000000;
	for (int i = s; i < e; i++) {
		int temp = 0;
		temp += func(s, i);
		temp += func(i + 1, e);
		temp += sum[e] - sum[s - 1];
		if (ret > temp) {
			ret = temp;
		}
	}
	return dp[s][e] = ret;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = -1;
			}
		}
		cout << func(1, n) << endl;
	}
	return 0;
}