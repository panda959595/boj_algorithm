#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stru {
	int x, y;
};
bool bigyo(stru a, stru b) {
	if (a.x != b.x) {
		return a.x > b.x;
	}
	else {
		return a.y < b.y;
	}
}
int main() {
	int n;
	cin >> n;
	vector<stru> vec;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({ x, y });
	}
	sort(vec.begin(), vec.end(), bigyo);
	int ans = 0;
	for (int i = 5; i < n; i++) {
		if (vec[i].x == vec[4].x) {
			ans++;
		}
		else {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}