#include <iostream>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;
		multiset<int> a;
		for (int i = 0; i < k; i++) {
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') {
				a.insert(n);
			}
			else {
				if (a.empty()) {
					continue;
				}
				if (n == 1) {
					a.erase(--a.end());
				}
				else {
					a.erase(a.begin());
				}
			}
		}
		if (a.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << *(--a.end()) << " " << *(a.begin()) << "\n";
		}
	}
	return 0;
}