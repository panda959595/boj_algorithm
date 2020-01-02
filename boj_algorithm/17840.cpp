#include <iostream>
#include <vector>
using namespace std;
long long n;
int m, q;
vector<int> vec;
vector<int> ans;
bool check[1000000];
void func(int n) {
	int arr[3] = { 100,10,1 };
	bool flag = false;
	for (int i = 0; i < 3; i++) {
		if (n >= arr[i]) {
			ans.push_back(n / arr[i]);
			flag = true;
			n %= arr[i];
		}
		else if (flag) {
			ans.push_back(0);
		}
	}
	if (!flag) {
		ans.push_back(0);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q >> m;
	int a = 1;
	int b = 1;
	int c;
	vec.push_back(a);
	vec.push_back(b);
	while (!check[1000 * a + b]) {
		check[1000 * a + b] = true;
		c = (a + b) % m;
		a = b;
		b = c;
		vec.push_back(c);
	}
	vec.pop_back();
	vec.pop_back();
	for (int i = 0; i < vec.size(); i++) {
		func(vec[i]);
	}
	while (q--) {
		cin >> n;
		n--;
		n %= ans.size();
		cout << ans[n] << "\n";
	}
	return 0;
}