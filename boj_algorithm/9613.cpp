#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {//a>b
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[105];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(max(arr[i], arr[j]), min(arr[i], arr[j]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}