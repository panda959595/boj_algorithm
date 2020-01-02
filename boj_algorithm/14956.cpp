#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int turn;
pair<int, int> arr[5] = { {0,0}, {1,1},{1,2},{2,2},{2,1} };
pair<int, int> func(long long n, long long m) {
	if (n == 2) {
		return arr[m];
	}
	pair<int, int> ret = { 0,0 };
	pair<int, int> temp;
	pair<int, int> tmp;
	if (m <= (n * n) / 4) {
		tmp = func(n / 2, (n*n) / 4 - m + 1);
		temp.first = tmp.second;
		temp.second = n / 2 - tmp.first + 1;
		ret.first += temp.first;
		ret.second += temp.second;
	}
	else if (m <= (n*n) / 2) {
		temp = func(n / 2, m - (n * n) / 4);
		ret.first += temp.first;
		ret.second += temp.second;
		ret.second += n / 2;
	}
	else if (m <= (n*n) * 3 / 4) {
		temp = func(n / 2, m - (n * n) / 2);
		ret.first += temp.first;
		ret.second += temp.second;
		ret.first += n / 2;
		ret.second += n / 2;
	}
	else {
		tmp = func(n / 2, (n*n) - m + 1);
		temp.first = n / 2 - tmp.second + 1;
		temp.second = tmp.first;
		ret.first += temp.first;
		ret.second += temp.second;
		ret.first += n / 2;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, m;
	cin >> n >> m;

	pair<int, int> ans = func(n, m);
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}