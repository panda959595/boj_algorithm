#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[1005];
	int re_arr[1005];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		re_arr[n - i - 1] = arr[i];
	}
	int LIS[1005];
	LIS[0] = 1;
	vector<int> vec;
	vec.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (vec[vec.size() - 1] < arr[i]) {
			vec.push_back(arr[i]);
			LIS[i] = vec.size();
		}
		else {
			vector<int>::iterator ite = lower_bound(vec.begin(), vec.end(), arr[i]);
			*ite = arr[i];
			LIS[i] = ite - vec.begin() + 1;
		}
	}
	int re_LIS[1005];
	re_LIS[0] = 1;
	vec.clear();
	vec.push_back(re_arr[0]);
	for (int i = 1; i < n; i++) {
		if (vec[vec.size() - 1] < re_arr[i]) {
			vec.push_back(re_arr[i]);
			re_LIS[i] = vec.size();
		}
		else {
			vector<int>::iterator ite = lower_bound(vec.begin(), vec.end(), re_arr[i]);
			*ite = re_arr[i];
			re_LIS[i] = ite - vec.begin() + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < LIS[i] + re_LIS[n - i - 1] - 1) {
			ans = LIS[i] + re_LIS[n - i - 1] - 1;
		}
	}
	cout << ans << endl;
	return 0;
}