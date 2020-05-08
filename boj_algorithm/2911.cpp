#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> arr[100005];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);
	int pre;
	long long ans;
	pre = -2;
	ans = 0;
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (num < arr[i].second) {
			ans += arr[i].second - num;
		}
		pre = arr[i].first;
		num = arr[i].second;
	}
	cout << ans << endl;
	return 0;
}