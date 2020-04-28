#include <iostream>
#include <vector>
using namespace std;
int shirt[205], kara[205];
vector<int> road[205];
bool shirt_check[205];
int kara_check[205];
bool bi_match(int shirt_num) {
	shirt_check[shirt_num] = false;
	for (auto k : road[shirt_num]) {
		if (kara_check[k] == -1 || (shirt_check[kara_check[k]] && bi_match(kara_check[k]))) {
			kara_check[k] = shirt_num;
			return true;
		}
	}
	return false;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> shirt[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> kara[i];
		kara_check[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((shirt[i] <= 2 * kara[j] && shirt[i] * 3 >= kara[j] * 4) || (shirt[i] <= kara[j] && shirt[i] * 5 >= kara[j] * 4)) {
				road[i].push_back(j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			shirt_check[j] = true;
		}
		if (bi_match(i)) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}