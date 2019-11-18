//9012
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int open = 0;
		string str;
		cin >> str;

		int len = str.length();
		for (int j = 0; j < len; j++) {
			if (str[j] == '(') {
				open++;
			}
			if (str[j] == ')'){
				open--;
			}
			if (open < 0) {
				break;
			}
		}
		if (open == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}