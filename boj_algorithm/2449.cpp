#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int dp[205][205];
int arr[205];
int func(int l,int r) {
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	int index = l;
	int ret = 10000000;
	while (index < r) {
		if (arr[index] != arr[index + 1]) {
			int temp = 1;
			if (arr[l] == arr[index + 1]) {
				temp = 0;
			}
			ret = min(ret, func(l, index) + func(index + 1, r) + temp);
		}
		index++;
	}
	if (ret == 10000000) {
		ret = 0;
	}
	return dp[l][r] = ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < 205; i++) {
		for (int j = 0; j < 205; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 10000000;
	ans = min(ans, func(0, n - 1));
	cout << ans << endl;
	return 0;
}