#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	int n = 1;
	while (n <= x || n <= y) {
		n *= 3;
	}
	n /= 3;
	int ans = 1;
	while (n > 0) {
		if (x >= n&&y >= n) {
			ans = 0;
			break;
		}
		else if (x >= n) {
			x -= n;
			n /= 3;
		}
		else if (y >= n) {
			y -= n;
			n /= 3;
		}
		else {
			ans = 0;
			break;
		}
	}
	if (x == 0 && y == 0 && ans == 1) {
		cout << ans << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}