#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr;
int n;
bool check[2000005];
int cnt[2000005];
int che[2000005];
vector<int> prime;
int ans;
int func(int num) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int temp = arr[i] % num;
		if (che[temp] != num) {
			che[temp] = num;
			cnt[temp] = 1;
		}
		else {
			cnt[temp]++;
		}
		ret = max(ret, cnt[temp]);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 2; i < arr[n - 1]; i++) {
		if (check[i]) {
			continue;
		}
		if (i * (n / 2 - 1) > arr[n - 1]) {
			break;
		}
		prime.push_back(i);
		for (int j = 2; j * i < arr[n - 1]; j++) {
			check[j * i] = true;
		}
	}
	for (int i = 0; i < prime.size(); i++) {
		ans = max(ans, func(prime[i]));
	}
	cout << ans;
	return 0;
}