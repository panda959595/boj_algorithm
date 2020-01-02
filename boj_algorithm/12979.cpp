#include <iostream>
using namespace std;
int ans = 2000000000;
void func(int w, int h, int a, int i) {
	if ((i > w) || (a / i > h)) {
		return;
	}
	int temp = 0;
	while (w > i * 2) {
		temp++;
		w = (w + 1) / 2;
	}
	if (w != i) {
		temp++;
	}
	while (h > a / i * 2) {
		temp++;
		h = (h + 1)/ 2;
	}
	if (h != a / i) {
		temp++;
	}
	if (ans > temp) {
		ans = temp;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int w, h, a;
	cin >> w >> h >> a;
	for (int i = 1; i <= a; i++) {
		if (a%i != 0) {
			continue;
		}
		func(w, h, a, i);
	}
	if (ans != 2000000000) {
		cout << ans << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}