#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check[100000005];
int ans;
int combination[15];
int arr[15];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++) {
		combination[i] = 1;
	}
	sort(combination, combination + n);
	do {
		vector<int> permu;
		for (int i = 0; i < n; i++) {
			if (combination[i] == 1) {
				permu.push_back(arr[i]);
			}
		}
		sort(permu.begin(), permu.end());
		do {
			int temp = 0;
			for (int i = 0; i < k; i++) {
				if (permu[i] >= 10) {
					temp *= 100;
				}
				else {
					temp *= 10;
				}
				temp += permu[i];
			}
			if (!check[temp]) {
				ans++;
				check[temp] = true;
			}
		} while (next_permutation(permu.begin(), permu.end()));
	} while (next_permutation(combination, combination + n));
	cout << ans << "\n";
	return 0;
}