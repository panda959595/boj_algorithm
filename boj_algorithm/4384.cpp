#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int a, b;
	a = b = 0;
	cin >> n;
	int arr[105];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--) {
		if (i == 0) {
			a += arr[i];
			if (a > b) {
				int temp = a;
				a = b;
				b = temp;
			}
			break;
		}
		a += arr[i];
		b += arr[i - 1];
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		i--;
	}
	cout << a << " " << b << endl;
	return 0;
}