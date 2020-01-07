#include <iostream>
#include <string>
using namespace std;
int dp[5005];
int main() {
	string str;
	cin >> str;
	dp[0] = 1;
	if (str[0] != '0') {
		dp[1] = 1;
	}
	for (int i = 2; i <= str.length(); i++) {
		if (str[i - 1] != '0') {
			dp[i] = dp[i - 1];
		}
		if (str[i - 2] == '1' || (str[i - 2] == '2' && str[i - 1] <= '6')) {
			dp[i] += dp[i - 2];
		}
		dp[i] %= 1000000;
	}
	cout << dp[str.length()] << endl;
	return 0;
}