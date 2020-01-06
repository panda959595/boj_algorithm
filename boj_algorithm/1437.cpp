#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 1;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	while (n > 1) {
		if (n == 4) {
			ans *= 4;
			n = 0;
		}
		else if (n == 2) {
			ans *= 2;
			n = 0;
		}
		else {
			n -= 3;
			ans *= 3;
			ans %= 10007;
		}
	}
	ans %= 10007;
	cout << ans << endl;
	return 0;
}