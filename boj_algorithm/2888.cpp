#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int func(vector<pair<int, int> >s) {
	vector<int> vec[1005];
	vector<int> sum[1005];
	vec[s[0].first].push_back(s[0].second);
	sum[s[0].first].push_back(s[0].second);
	int ret = 0;
	for (int i = 1; i < s.size(); i++) {
		for (int j = 0; j < s[i].first; j++) {
			if (vec[j].size() == 0) {
				continue;
			}
			vector<int>::iterator ite1 = lower_bound(vec[j].begin(), vec[j].end(), s[i].second - (s[i].first - j));
			if (vec[j][vec[j].size() - 1] < s[i].second - (s[i].first - j)) {
				ite1 = vec[j].end() - 1;
			}
			if (*ite1 >= s[i].second - (s[i].first - j) && ite1 != vec[j].begin()) {
				ite1--;
			}
			if (*ite1 <= s[i].second - (s[i].first - j)) {
				ret += (s[i].second - (s[i].first - j)) * (ite1 - vec[j].begin() + 1) - sum[j][ite1 - vec[j].begin()];
			}
			if (*ite1 == s[i].second - (s[i].first - j)) {
				ite1++;
			}
			vector<int>::iterator ite2 = lower_bound(vec[j].begin(), vec[j].end(), s[i].second + (s[i].first - j));
			if (vec[j][vec[j].size() - 1] < s[i].second + (s[i].first - j)) {
				ite2 = vec[j].end() - 1;
			}
			if (*ite2 == s[i].second + (s[i].first - j) && ite2 != vec[j].begin()) {
				ite2--;
			}
			if (ite2 >= ite1 && *ite2 < s[i].second + (s[i].first - j) && *ite2>s[i].second - (s[i].first - j)) {
				ret += (s[i].first - j) * (ite2 - ite1 + 1);
			}
			ite1 = lower_bound(vec[j].begin(), vec[j].end(), s[i].second + (s[i].first - j));
			if (vec[j][vec[j].size() - 1] < s[i].second + (s[i].first - j)) {
				continue;
			}
			if (*ite1 >= s[i].second + (s[i].first - j)) {
				ret += (sum[j][sum[j].size() - 1] - sum[j][ite1 - vec[j].begin()]);
				ret -= (s[i].second - (s[i].first - j)) * (vec[j].end() - ite1);
			}
		}
		if (sum[s[i].first].size() == 0) {
			sum[s[i].first].push_back(s[i].second);
		}
		else {
			ret += sum[s[i].first].size() * s[i].second - sum[s[i].first][sum[s[i].first].size() - 1];
			vec[s[i].first].push_back(s[i].second);
			sum[s[i].first].push_back(sum[s[i].first][sum[s[i].first].size() - 1] + s[i].second);
		}
	}
	for (int i = 0; i < 1001; i++) {
		vec[i].clear();
		sum[i].clear();
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > s;
	vector<pair<int, int> > y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'M') {
				s.push_back({ i,j });
			}
			else if (c == 'S') {
				y.push_back({ i,j });
			}
		}
	}
	sort(s.begin(), s.end());
	sort(y.begin(), y.end());
	int ans_s = func(s);
	int ans_y = func(y);
	cout << ans_s << " " << ans_y;

	return 0;
}