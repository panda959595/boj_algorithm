#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int ans = a.length();
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int temp = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[i + j]) {
				temp++;
			}
		}
		if (ans > temp) {
			ans = temp;
		}
	}
	cout << ans << "\n";
	return 0;
}