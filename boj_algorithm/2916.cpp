#include <iostream>
#include <vector>
using namespace std;
vector<int> func(vector<int> vec) {
	bool check[360];
	for (int i = 0; i < 360; i++) {
		check[i] = false;
	}
	for (int i = 0; i < vec.size(); i++) {
		check[vec[i]] = true;
	}
	vector<int> a;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			int temp = abs(vec[i] - vec[j]);
			if (!check[temp]) {
				a.push_back(temp);
				check[temp] = true;
			}
			temp = vec[i] + vec[j];
			temp %= 360;
			if (!check[temp]) {
				a.push_back(temp);
				check[temp] = true;
			}
		}
	}
	if (a.empty()) {
		return vec;
	}
	vector<int> b;
	int n, m;
	n = m = 0;
	while (1) {
		if (n < vec.size() && m < a.size()) {
			if (vec[n] < a[m]) {
				b.push_back(vec[n++]);
			}
			else {
				b.push_back(a[m++]);
			}
		}
		else if (n < vec.size()) {
			b.push_back(vec[n++]);
		}
		else if (m < a.size()) {
			b.push_back(a[m++]);
		}
		else {
			break;
		}
	}
	return func(b);
}
int main() {
	vector<int> vec;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	vec = func(vec);
	bool check[360];
	for (int i = 0; i < 360; i++) {
		check[i] = false;
	}
	for (int i = 0; i < vec.size(); i++) {
		check[vec[i]] = true;
	}
	check[0] = true;
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		if (check[temp]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}