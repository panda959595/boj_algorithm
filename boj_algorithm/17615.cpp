#include <iostream>
using namespace std;
int arr[500005];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'R') {
			arr[i] = 1;
		}
	}
	int ans = 1000000000;
	int temp;
	bool flag;
	//0�� ����
	temp = 0;
	flag = true;
	for (int i = 0; i < n; i++) {
		if (flag) {
			if (arr[i] == 1) {
				flag = false;
			}
		}
		else {
			if (arr[i] == 0) {
				temp++;
			}
		}
	}
	if (ans > temp) {
		ans = temp;
	}
	//1�� ����
	temp = 0;
	flag = true;
	for (int i = 0; i < n; i++) {
		if (flag) {
			if (arr[i] == 0) {
				flag = false;
			}
		}
		else {
			if (arr[i] == 1) {
				temp++;
			}
		}
	}
	if (ans > temp) {
		ans = temp;
	}
	//0�� ������
	temp = 0;
	flag = true;
	for (int i = n - 1; i >= 0; i--) {
		if (flag) {
			if (arr[i] == 1) {
				flag = false;
			}
		}
		else {
			if (arr[i] == 0) {
				temp++;
			}
		}
	}
	if (ans > temp) {
		ans = temp;
	}
	//1�� ������
	temp = 0;
	flag = true;
	for (int i = n - 1; i >= 0; i--) {
		if (flag) {
			if (arr[i] == 0) {
				flag = false;
			}
		}
		else {
			if (arr[i] == 1) {
				temp++;
			}
		}
	}
	if (ans > temp) {
		ans = temp;
	}
	cout << ans << endl;
	return 0;
}