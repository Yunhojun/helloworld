#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int res = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		int sqrtn = floor(sqrt(num));
		if (sqrtn == 1) {
			if (num != 1) {
				res++;
			}
		}
		else {
			for (int j = 2; j <= sqrtn; j++) {
				if (num%j == 0) {
					res--;
					break;
				}
			}
			res++;
		}
	}
	cout << res;
}