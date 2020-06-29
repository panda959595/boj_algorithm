#include <iostream>
#include <algorithm>
using namespace std;
char arr[1000005];
int a[1000005];
int b[1000005];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (arr[0] == 'A') {
		a[0] = 0;
		b[0] = 1;
	}
	else {
		a[0] = 1;
		b[0] = 0;
	}
	for (int i = 1; i < n; i++) {
		if (arr[i] == 'A') {
			a[i] = min(a[i - 1], b[i - 1] + 1);
			b[i] = 1 + min(a[i - 1], b[i - 1]);
		}
		else {
			b[i] = min(a[i - 1] + 1, b[i - 1]);
			a[i] = 1 + min(a[i - 1], b[i - 1]);
		}
	}
	cout << a[n - 1] << endl;
	return 0;
}