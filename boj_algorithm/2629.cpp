#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool dp[2400005];
vector<int> vec;
vector<int> temp;
int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	dp[1200001] = true;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < 2400005; j++) {
			if (!dp[j]) {
				continue;
			}
			if (j - vec[i] > 0) {
				dp[j - vec[i]] = true;
			}
			if (j + vec[i] < 2400005 && !dp[j + vec[i]]) {
				temp.push_back(j + vec[i]);
			}
		}
		for (int j = 0; j < temp.size(); j++) {
			dp[temp[j]] = true;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		tmp += 1200001;
		if (dp[tmp]) {
			cout << "Y ";
		}
		else {
			cout << "N ";
		}
	}
	return 0;
}