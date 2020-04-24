#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000005];
int brr[2000005];
int palin_odd[1000005];
int palin_even[2000005];
int n;
void manacher_odd() {
	int r, j;
	palin_odd[0] = 0;
	j = 0;
	r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) {
			palin_odd[i] = 0;
			palin_odd[i] = min(r - i, palin_odd[2 * j - i]);
		}
		while (i + palin_odd[i] + 1 < n && i - palin_odd[i] - 1 >= 0) {
			if (arr[i + palin_odd[i] + 1] == arr[i - palin_odd[i] - 1]) {
				palin_odd[i]++;
			}
			else {
				break;
			}
		}
		if (palin_odd[i] + i > r) {
			r = palin_odd[i] + i;
			j = i;
		}
	}
}
void manacher_even() {
	int r, j;
	palin_even[0] = 0;
	j = 0;
	r = 0;
	for (int i = 1; i < 2 * n - 1; i++) {
		if (i <= r) {
			palin_even[i] = 0;
			palin_even[i] = min(r - i, palin_even[2 * j - i]);
		}
		while (i + palin_even[i] + 1 < 2 * n - 1 && i - palin_even[i] - 1 >= 0) {
			if (brr[i + palin_even[i] + 1] == brr[i - palin_even[i] - 1]) {
				palin_even[i]++;
			}
			else {
				break;
			}
		}
		if (palin_even[i] + i > r) {
			r = palin_even[i] + i;
			j = i;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		brr[2 * i] = arr[i];
	}
	manacher_odd();
	manacher_even();
	int m;
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if ((b - a) % 2 == 0) {
			if (palin_odd[(b + a) / 2] >= (b - a) / 2) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else {
			if (palin_even[b + a] >= b - a) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
	}
	return 0;
}