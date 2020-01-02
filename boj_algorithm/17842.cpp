#include <iostream>
using namespace std;
int check[200005];
int main() {
	int n;
	cin >> n;
	int ans = n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		check[a]++;
		check[b]++;
		if (check[a] == 2) {
			ans--;
		}
		if (check[b] == 2) {
			ans--;
		}
	}
	ans++;
	ans /= 2;
	cout << ans << "\n";
	return 0;
}