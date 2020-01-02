#include <iostream>
using namespace std;
int main() {
	int m;
	cin >> m;
	long long ans = 1;
	int s = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ans *= b;
		ans /= a;
		s ^= c;
	}
	cout << s << " " << ans << endl;
	return 0;
}