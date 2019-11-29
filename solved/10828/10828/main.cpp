//10828 ╫╨ец
#include <iostream>
#include <string>
using namespace std;

int main() {
	int stack[200] = { 0 };
	int n = 0;
	int top = 0;
	cin >> n;
	string input;
	
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			int j = 0;
			cin >> j;
			stack[top] = j;
			top++;
		}
		else if (input == "pop") {
			if (top >= 1) {
				cout << stack[top - 1] << endl;
				top--;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (input == "size") {
			cout << top << endl;
		}
		else if (input == "empty") {
			if (top >= 1) {
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		else if (input == "top") {
			if (top >= 1) {
				cout << stack[top - 1] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
}