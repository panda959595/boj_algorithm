#include <iostream>
using namespace std;
int arr[1500005];
int main() {
	long long n;
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < 1500005; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
	}
	cin >> n;
	cout << arr[n % 1500000] << endl;
	return 0;
}