#include <iostream>
#include <malloc.h>
#include <algorithm>
using namespace std;
class big_int {
public:
	big_int() {
		len = 1;
		num = (int *)malloc(sizeof(int)*len);
		num[0] = 0;
	}
	big_int(int n) {
		len = 1;
		num = (int *)malloc(sizeof(int)*len);
		num[0] = n;
		up_carry();
	}
	big_int(const big_int &n) {
		len = n.len;
		num = (int *)malloc(sizeof(int)*len);
		for (int i = 0; i < len; i++) {
			num[i] = n.num[i];
		}
	}
	big_int(int l, int* n) {
		len = l;
		num = (int *)malloc(sizeof(int)*len);
		for (int i = 0; i < len; i++) {
			num[i] = n[i];
		}
	}
	~big_int() {
		if (num != NULL) {
			delete num;
		}
	}
	void print() {
		for (int i = 0; i < len; i++) {
			cout << num[i];
		}
		cout << "\n";
	}
	big_int operator=(int n) {
		if (num != NULL) {
			delete num;
		}
		len = 1;
		num = (int *)malloc(sizeof(int)*len);
		num[0] = n;
		return *this;
	}
	big_int operator=(const big_int &n) {
		if (num != NULL) {
			delete num;
		}
		len = n.len;
		num = (int *)malloc(sizeof(int)*len);
		for (int i = 0; i < len; i++) {
			num[i] = n.num[i];
		}
		return *this;
	}
	void up_carry() {
		for (int i = len - 1; i > 0; i--) {
			if (num[i] >= 10) {
				num[i - 1] += num[i] / 10;
				num[i] %= 10;
			}
		}
		if (num[0] >= 10) {
			int carry_size = 0;
			int temp = num[0];
			while (temp >= 10) {
				carry_size++;
				temp /= 10;
			}
			int *num_temp = (int *)malloc(sizeof(int)*(carry_size + len));
			for (int i = 0; i < len; i++) {
				num_temp[carry_size + len - 1 - i] = num[len - 1 - i];
			}
			for (int i = carry_size - 1; i >= 0; i--) {
				num_temp[i] = num_temp[i + 1] / 10;
				num_temp[i + 1] %= 10;
			}
			len += carry_size;
			delete num;
			num = num_temp;
		}
	}
	void down_carry() {
		for (int i = len - 1; i > 0; i--) {
			if (num[i] < 0) {
				num[i - 1]--;
				num[i] += 10;
			}
		}
		while (len > 1 && num[0] == 0) {
			int down_size = 0;
			for (int i = 0; i < len - 1; i++) {
				if (num[i] != 0) {
					break;
				}
				down_size++;
			}
			int *num_temp = (int *)malloc(sizeof(int)*(len - down_size));
			for (int i = 0; i < len - down_size; i++) {
				num_temp[i] = num[i + down_size];
			}
			delete num;
			num = num_temp;
			len -= down_size;
		}
	}
	big_int operator+(const big_int &n) {
		int max_len = max(len, n.len);
		int *temp = (int *)malloc(sizeof(int) * max_len);
		int i, j;
		i = len - 1;
		j = n.len - 1;
		for (int k = max_len - 1; k >= 0; k--) {
			if (i >= 0 && j >= 0) {
				temp[k] = num[i] + n.num[j];
				i--;
				j--;
			}
			else if (i >= 0) {
				temp[k] = num[i];
				i--;
			}
			else if (j >= 0) {
				temp[k] = n.num[j];
				j--;
			}
			else {
				temp[k] = 0;
			}
		}
		big_int ret(max_len, temp);
		ret.up_carry();
		delete temp;
		return ret;
	}
	big_int operator+(const int &n) {
		num[len - 1] += n;
		up_carry();
		return *(this);
	}
	big_int operator-(const big_int &n) {
		int *temp = (int *)malloc(sizeof(int) * len);
		int i, j;
		i = len - 1;
		j = n.len - 1;
		for (int k = len - 1; k >= 0; k--) {
			if (i >= 0 && j >= 0) {
				temp[k] = num[i] - n.num[j];
				i--;
				j--;
			}
			else {
				temp[k] = num[k];
			}
		}
		big_int ret(len, temp);
		ret.down_carry();
		delete temp;
		return ret;
	}
	big_int operator-(const int &n) {
		num[0] -= n;
		down_carry();
		return *(this);
	}
	big_int operator*(const big_int &n) {
		big_int ret;
		big_int temp = *this;
		for (int i = n.len - 1; i >= 0; i--) {
			for (int j = 0; j < len; j++) {
				temp.num[j] = num[j] * n.num[i];
			}
			ret = ret + temp;
			ret.up_carry();
			temp = temp * 10;
		}
		return ret;
	}
	big_int operator*(const int &n) {
		for (int i = 0; i < len; i++) {
			num[i] *= n;
		}
		up_carry();
		return *(this);
	}
	big_int operator/(const big_int &n) {
		if (*this < n) {
			return 0;
		}
		int i = 0;
		big_int temp(n);
		int *ret_temp = (int *)malloc(sizeof(int)*(len - n.len + 1));
		for (int i = 0; i < len - n.len + 1; i++) {
			ret_temp[i] = 0;
		}
		for (int j = 0; j < temp.len; j++) {
			temp.num[j] = num[i + j];
		}
		while (i < len - n.len + 1) {
			temp.down_carry();
			while (temp >= n) {
				temp = temp - n;
				ret_temp[i]++;
			}
			i++;
			temp = temp * 10;
			temp = temp + num[i + n.len - 1];
		}
		big_int ret(len - n.len + 1, ret_temp);
		ret.down_carry();
		delete ret_temp;
		return ret;
	}
	big_int operator%(const big_int &n) {
		big_int temp = *(this) / n;
		big_int ret = *(this) - temp * n;
		ret.down_carry();
		return ret;
	}
	bool operator>(const big_int &n) {
		if (len != n.len) {
			return len > n.len;
		}
		for (int i = 0; i < len; i++) {
			if (num[i] != n.num[i]) {
				return num[i] > n.num[i];
			}
		}
		return false;
	}
	bool operator<(const big_int &n) {
		if (len != n.len) {
			return len < n.len;
		}
		for (int i = 0; i < len; i++) {
			if (num[i] != n.num[i]) {
				return num[i] < n.num[i];
			}
		}
		return false;
	}
	bool operator==(const big_int &n) {
		if (len != n.len) {
			return false;
		}
		for (int i = 0; i < len; i++) {
			if (num[i] != n.num[i]) {
				return false;
			}
		}
		return true;
	}
	bool operator>=(const big_int &n) {
		if ((*this) < n) {
			return false;
		}
		else {
			return true;
		}
	}
	bool operator<=(const big_int &n) {
		if ((*this) > n) {
			return false;
		}
		else {
			return true;
		}
	}
private:
	int *num;
	int len;
};
big_int a[1000000];
int main() {
	a[1] = 1;
	a[2] = 1;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	a[n].print();
	return 0;
}