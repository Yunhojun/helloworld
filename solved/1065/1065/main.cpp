//1~99까지 99개 100~110 0개/ 111~210 111 123 135 147 159 210 6개
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (i < 100) {
			res++;
		}
		else{
			string str = to_string(i);
			int len = str.length();
			int temp = str[0] - str[1];
			for (int j = 1; j < len - 1; j++) {
				if (temp != str[j] - str[j + 1]) {
					break;
				}
				
			}
		}
	}
}