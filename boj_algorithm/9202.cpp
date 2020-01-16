#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int score_get[9] = { 0,0,0,1,1,2,3,5,11 };
struct node {
	node* next[26];
	string str;
	int finish;
	node() {
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
		finish = -1;
		str = "";
	}
};
struct stru {
	node* state;
	int x, y;
	int check;
};
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
node* a;
queue<stru> que;
vector<string> vec;
int main() {
	int w;
	cin >> w;
	a = new node;
	for (int i = 0; i < w; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
		node* now = a;
		for (int j = 0; j < temp.length(); j++) {
			if (now->next[temp[j] - 'A'] != NULL) {
				now = now->next[temp[j] - 'A'];
			}
			else {
				node* new_node = new node;
				now->next[temp[j] - 'A'] = new_node;
				new_node->str = now->str + temp[j];
				now = new_node;
			}
		}
		now->finish = i;
	}
	int b;
	cin >> b;
	while (b--) {
		string board[4];
		for (int i = 0; i < 4; i++) {
			cin >> board[i];
			for (int j = 0; j < 4; j++) {
				if (a->next[board[i][j] - 'A'] != NULL) {
					stru temp;
					temp.x = i;
					temp.y = j;
					temp.state = a->next[board[i][j] - 'A'];
					temp.check = 1 << (4 * i + j);
					que.push(temp);
				}
			}
		}
		bool check[300005];
		memset(check, 0, sizeof(check));
		while (!que.empty()) {
			stru now = que.front();
			que.pop();
			if (now.state->finish != -1) {
				check[now.state->finish] = true;
			}
			if (now.state->str.length() == 8) {
				continue;
			}
			for (int i = 0; i < 8; i++) {
				if (now.x + dx[i] >= 0 && now.x + dx[i] < 4 && now.y + dy[i] >= 0 && now.y + dy[i] < 4) {
					stru temp;
					temp.x = now.x + dx[i];
					temp.y = now.y + dy[i];
					if ((now.check & (1 << (temp.x * 4 + temp.y))) == 0 && now.state->next[board[temp.x][temp.y] - 'A'] != NULL) {
						temp.state = now.state->next[board[temp.x][temp.y] - 'A'];
						temp.check = now.check | (1 << (temp.x * 4 + temp.y));
						que.push(temp);
					}
				}
			}
		}
		string longest_str = "Z";
		int score = 0;
		int find_num = 0;
		for (int i = 0; i < w; i++) {
			if (check[i]) {
				//cout << i << endl;
				find_num++;
				score += score_get[vec[i].length()];
				if ((longest_str.length() == vec[i].length() && longest_str > vec[i])|| longest_str.length() < vec[i].length()) {
					longest_str = vec[i];
				}
			}
		}
		cout << score << " " << longest_str << " " << find_num << endl;
	}
	return 0;
}