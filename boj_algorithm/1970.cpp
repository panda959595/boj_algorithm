#include <iostream>
#include <algorithm>
using namespace std;
int dp[1005][1005];
int brand[1005];
int ans = 0;
int func(int s, int e) {
	if (e < s) {
		return 0;
	}
	if (dp[s][e] != -1) {
		return dp[s][e];
	}
	if (s == e) {
		return dp[s][e] = 0;
	}
	else if (e == s + 1) {
		if (brand[s] == brand[e]) {
			return dp[s][e] = 1;
		}
		else {
			return dp[s][e] = 0;
		}
	}
	int ret = func(s + 1, e);
	for (int i = s + 1; i <= e; i++) {
		if (brand[i] == brand[s]) {
			ret = max(ret, func(s + 1, i - 1) + func(i + 1, e) + 1);
		}
	}
	return dp[s][e] = ret;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> brand[i + 1]; 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	func(1, n);
	cout << dp[1][n] << endl;
	return 0;
}