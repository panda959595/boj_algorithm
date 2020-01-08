#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long arr[15][10];
long long zrr[15][10];
long long ans[10];
long long lpow(long long a,int b) {
	long long ret = 1;
	while (b--) {
		ret *= a;
	}
	return ret;
}
void zfunc(long long n) {
	long long temp = 1;
	if (n == 0) {
		return;
	}
	if (n < 10) {
		for (int i = 0; i <= n; i++) {
			ans[i]++;
		}
		return;
	}
	int index;
	for (int i = 1; temp * 10 <= n; i++) {
		index = i;
		temp *= 10;
	}
	for (int i = 0; i < 10; i++) {
		ans[i] += zrr[index][i];
	}
	for (int i = 0; i < 10; i++) {
		ans[i] += zrr[index][i] * (n / temp - 1);
	}
	for (int i = 0; i < n / temp; i++) {
		ans[i] += temp;
	}
	ans[n / temp] += n % temp + 1;
	if (n == temp) {
		ans[0] += index;
		return;
	}
	long long t = temp;
	while (1) {
		if (n % t < t / 10) {
			ans[0] += n % t + 1;
		}
		else {
			break;
		}
		t /= 10;
	}
	zfunc(n % temp);
}
void func(long long n) {
	if (n < 10) {
		for (int i = 1; i <= n; i++) {
			ans[i]++;
		}
		return;
	}
	long long temp = 1;
	int index;
	for (int i = 1; temp * 10 <= n; i++) {
		for (int j = 0; j < 10; j++) {
			ans[j] += arr[i][j];
		}
		index = i;
		temp *= 10;
	}
	for (int i = 0; i < 10; i++) {
		ans[i] += zrr[index][i] * (n / temp - 1);
	}
	for (int i = 1; i < n / temp; i++) {
		ans[i] += temp;
	}
	ans[n / temp] += n % temp + 1;
	if (n == temp) {
		ans[0] += index;
		return;
	}
	long long t = temp;
	while (1) {
		if (n % t < t / 10) {
			ans[0] += n % t + 1;
		}
		else {
			break;
		}
		t /= 10;
	}
	zfunc(n % temp);
}
int main() {
	for (int i = 1; i < 10; i++) {
		arr[1][i] = 1;
	}
	for (int i = 2; i < 12; i++) {
		for (int j = 1; j < 10; j++) {
			arr[i][j] = lpow(10, i - 1) + lpow(10, i - 2) * 9 * (i - 1);
		}
		arr[i][0] = lpow(10, i - 2) * 9 * (i - 1);
	}
	for (int i = 1; i < 12; i++) {
		for (int j = 0; j < 10; j++) {
			zrr[i][j] = lpow(10, i - 1) * i;
		}
	}
	long long n;
	for (int i = 0; i < 10; i++) {
		ans[i] = 0;
	}
	cin >> n;
	func(n);
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}