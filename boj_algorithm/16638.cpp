#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int arr[25];
bool braket[25];
int n;
int alpha[999];
int calc_func(int a, int b, int c) {
	if (b == 2000000001) return a + c;
	else if (b == 2000000002) return a - c;
	else return a * c;
}
int calc() {
	stack<int> sta;
	for (int i = 0; i < n; i++) {
		int now = arr[i];
		if (braket[i]) {
			now = calc_func(arr[i], arr[i + 1], arr[i + 2]);
			i += 2;
		}
		if (!sta.empty()) {
			int top = sta.top();
			if (top == 2000000003) {
				sta.pop();
				top = sta.top();
				sta.pop();
				now *= top;
			}
		}
		sta.push(now);
	}
	int ret = sta.top();
	sta.pop();
	if (!sta.empty()) {
		int temp = sta.top();
		sta.pop();
		if (temp == 2000000002) {
			ret *= -1;
		}
	}
	while (!sta.empty()) {
		int a = sta.top();
		sta.pop();
		if (!sta.empty()) {
			int temp = sta.top();
			if (temp == 2000000002) {
				a *= -1;
			}
			sta.pop();
		}
		ret += a;
	}
	return ret;
}
int func(int num) {
	int ret = -2000000000;
	if (num >= n - 1) {
		int ret = calc();
		return ret;
	}
	braket[num] = true;
	int temp = func(num + 4);
	ret = max(ret, temp);
	braket[num] = false;
	temp = func(num + 2);
	ret = max(ret, temp);
	return ret;
}
int main() {
	for (int i = 0; i < 10; i++) {
		alpha[i + '0'] = i;
	}
	alpha['+'] = 2000000001;
	alpha['-'] = 2000000002;
	alpha['*'] = 2000000003;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		arr[i] = alpha[c];
	}
	cout << func(0);

	return 0;
}