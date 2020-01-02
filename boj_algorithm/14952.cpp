#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int map[5][5];
int n, m;
int arr[50000000];
int nt[3] = { 0,2,1 };
int calc() {
	int ret = 0;
	int temp = 1;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			ret += map[i][j] * temp;
			temp *= 3;
		}
	}
	return ret;
}
void func(int x, int y, int flag) {
	int temp = 1;
	for (int i = 1; i < 4; i++) {
		if (y + i <= 4 && map[x][y] == map[x][y + i]) {
			temp++;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 4; i++) {
		if (y - i >= 1 && map[x][y] == map[x][y - i]) {
			temp++;
		}
		else {
			break;
		}
	}
	if (temp >= 3) {
		if (x == n && y == m && map[x][y] == 2) {
			int tmp = calc();
			arr[tmp] = 1;
		}
		return;
	}
	temp = 1;
	for (int i = 1; i < 4; i++) {
		if (x + i <= 4 && map[x][y] == map[x + i][y]) {
			temp++;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 4; i++) {
		if (x - i >= 1 && map[x][y] == map[x - i][y]) {
			temp++;
		}
		else {
			break;
		}
	}
	if (temp >= 3) {
		if (x == n && y == m && map[x][y] == 2) {
			int tmp = calc();
			arr[tmp] = 1;
		}
		return;
	}
	temp = 1;
	for (int i = 1; i < 4; i++) {
		if (x + i <= 4 && y + i <= 4 && map[x][y] == map[x + i][y + i]) {
			temp++;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 4; i++) {
		if (x - i >= 1 && y - i >= 1 && map[x][y] == map[x - i][y - i]) {
			temp++;
		}
		else {
			break;
		}
	}
	if (temp >= 3) {
		if (x == n && y == m && map[x][y] == 2) {
			int tmp = calc();
			arr[tmp] = 1;
		}
		return;
	}
	temp = 1;
	for (int i = 1; i < 4; i++) {
		if (x - i >= 1 && y + i <= 4 && map[x][y] == map[x - i][y + i]) {
			temp++;
		}
		else {
			break;
		}
	}
	for (int i = 1; i < 4; i++) {
		if (x + i <= 4 && y - i >= 1 && map[x][y] == map[x + i][y - i]) {
			temp++;
		}
		else {
			break;
		}
	}
	if (temp >= 3) {
		if (x == n && y == m && map[x][y] == 2) {
			int tmp = calc();
			arr[tmp] = 1;
		}
		return;
	}
	if (x == n && y == m) {
		return;
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (map[i][j] == 0) {
				map[i][j] = flag;
				func(i, j, nt[flag]);
				map[i][j] = 0;
				break;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int temp;
	cin >> temp >> m >> n;
	map[temp][1] = 1;
	func(temp, 1, 2);
	int ans = 0;
	for (int i = 0; i < 50000000; i++) {
		ans += arr[i];
	}
	cout << ans << "\n";
	return 0;
}