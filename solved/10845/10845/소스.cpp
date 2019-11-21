#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> num;
	int front = 0;
	int back = 0;

	string input;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			int m;
			cin >> m;
			num.push_back(m);
			back++;
		}
		else if (input == "pop") {
			if (front == back) {
				cout << -1 << endl;
			}
			else {
				cout << num[front] << endl;
				front++;
			}
		}
		else if (input == "size") {
			cout << (back - front) << endl;
		}
		else if (input == "empty") {
			if (front == back) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (input == "front") {
			if (front == back) {
				cout << -1 << endl;
			}
			else {
				cout << num[front] << endl;
			}
		}
		else if (input == "back") {
			if (front == back) {
				cout << -1 << endl;
			}
			else {
				cout << num[back - 1] << endl;
			}
		}
	}
}