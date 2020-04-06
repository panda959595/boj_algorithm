#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec[1005];
const int middle = 502;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (n >= m * k + 1 || m + k - 1 > n) {
		cout << -1 << endl;
		return  0;
	}
	int index = 1;
	for (int i = 0; i < m; i++) {
		vec[middle + i].push_back(index);
		index++;
	}
	for (int i = 1; i < k; i++) {
		vec[middle - i].push_back(index);
		index++;
	}
	int temp_m = m - 1;
	int temp_k = k - 2;
	while (index <= n) {
		for (int i = 0; i < temp_m; i++) {
			if (index > n) {
				break;
			}
			vec[middle + i].push_back(index);
			index++;
		}
		temp_m--;
		for (int i = 1; i <= temp_k; i++) {
			if (index > n) {
				break;
			}
			vec[middle - i].push_back(index);
			index++;
		}
		temp_k--;
	}
	for (int i = middle - k + 1; i <= middle + m - 1; i++) {
		for (auto k : vec[i]) {
			cout << k << " ";
		}
	}
	return 0;
}