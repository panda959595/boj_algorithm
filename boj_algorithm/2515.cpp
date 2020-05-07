#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> arr[300005];
vector<int> lis;
vector<int> dp;
int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {	
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);
	lis.push_back(arr[0].first);
	dp.push_back(arr[0].second);
	int size = 1;
	for (int i = 1; i < n; i++) {
		vector<int>::iterator ite = upper_bound(lis.begin(), lis.end(), arr[i].first - s);
		int index = ite - lis.begin() - 1;
		if (index == -1) {
			if (arr[i].second > dp[size - 1]) {
				lis.push_back(arr[i].first);
				dp.push_back(arr[i].second);
				size++;
			}
		}
		else if (arr[i].second + dp[index] > dp[size - 1]) {
			lis.push_back(arr[i].first);
			dp.push_back(arr[i].second + dp[index]);
			size++;
		}
	}
	cout << dp[size - 1] << endl;
	return 0;
}