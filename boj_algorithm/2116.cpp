#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cube_index[10005][7];//해당 숫자가 몇번 인덱스에 있는지
int cube_num[10005][7];//해당 인덱스가 어떤 숫자가 있는지
int side[7][4] = {
	{2,3,4,5},
	{1,3,5,6},
	{1,2,4,6},
	{1,3,5,6},
	{1,2,4,6},
	{2,3,4,5}
};//
int op[6] = { 6,4,5,2,3,1 };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			int num;
			cin >> num;
			
		}
	}
	int up_down;
	int ans = 0;
	for (int i = 1; i <= 6; i++) {
		int ans_temp = 0;
		up_down = i;
		for (int j = 0; j < cube.size(); j++) {
			int now_temp = 0;
			for (int k = 0; k < 4; k++) {
				now_temp = max(now_temp, cube[j][side[up_down][k]]);
			}
			ans_temp += now_temp;
			up_down = op[up_down];
		}
		ans = max(ans, ans_temp);
	}
	cout << ans << endl;
	return 0;
}