#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stru {
	int x, y;
};
vector<stru> vec;
vector<int> ans;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b});
	}
	vec.push_back(vec[0]);
	int a, b;
	bool flag = false;
	cin >> a >> b;
	if (a == 0) {
		a = n;
	}
	if (b == 0) {
		b = n;
	}
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
		flag = true;
	}
	for (int i = a; i <= b; i++) {
		while(ans.size() >= 2 && 1LL * (vec[ans[ans.size() - 2]].x - vec[i].x)*(vec[ans[ans.size() - 2]].y - vec[ans[ans.size() - 1]].y) <=
			1LL * (vec[ans[ans.size() - 2]].x - vec[ans[ans.size() - 1]].x)*(vec[ans[ans.size() - 2]].y - vec[i].y)) {
			ans.pop_back();
		}
		ans.push_back(i);
	}
	if (flag) {
		reverse(ans.begin(), ans.end());
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == n) {
			ans[i] = 0;
		}
		cout << ans[i] << " ";
	}
	return 0;
}