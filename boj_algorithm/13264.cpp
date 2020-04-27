#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string str;
int arr[100005];
int g[100005];
int ng[100005];
int t;
bool bigyo(int a, int b) {
	if (g[a] == g[b]) {
		return g[a + t] < g[b + t];
	}
	else {
		return g[a] < g[b];
	}
}
void func() {
	int len = str.length();
	for (int i = 0; i < len; i++) {
		arr[i] = i;
		g[i] = str[i] -'a';
	}
	g[len] = -1;
	for (t = 1; t < len; t *= 2) {
		sort(arr, arr + len, bigyo);
		ng[0] = 0;
		ng[len] = -1;
		for (int i = 1; i < len; i++) {
			if (bigyo(arr[i - 1], arr[i])) {
				ng[arr[i]] = ng[arr[i - 1]] + 1;
			}
			else {
				ng[arr[i]] = ng[arr[i - 1]];
			}
		}
		for (int i = 0; i < len; i++) {
			g[i] = ng[i];
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	func();
	for (int i = 0; i < str.length(); i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}