#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100005];
int n;
long long func(long long num) {
	long long ret = 0;
	for (int i = 1; i < n; i++) {
		ret += abs(num * i - arr[i]);
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long right = 0;
	for (int i = 1; i < n; i++) {
		right = max(right, arr[i] - arr[i - 1]);
	}
	long long left = 1;
	long long ans = min(func(left), func(right));
	while (right > left) {
		long long m = func((left + right) / 2);
		long long l = func((left + right) / 2 - 1);
		long long r = func((left + right) / 2 + 1);
		ans = min(min(ans, l), min(r, m));
		if (right == left + 1) {
			break;
		}
		if (l < r) {
			right = (left + right) / 2;
		}
		else {
			left = (left + right) / 2;
		}
	}
	cout << ans << endl;
	return 0;
}