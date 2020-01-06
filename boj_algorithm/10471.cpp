#include <iostream>
using namespace std;
int arr[105];
bool ans[105];
int main() {
	int w, p;
	cin >> w >> p;
	for (int i = 0; i < p; i++) {
		cin >> arr[i + 1];
	}
	arr[p + 1] = w;
	for (int i = 1; i < p + 2; i++) {
		for (int j = 0; j < i; j++) {
			ans[arr[i] - arr[j]] = true;
		}
	}
	for (int i = 1; i <= w; i++) {
		if (ans[i]) {
			cout << i << " ";
		}
	}
	return 0;
}