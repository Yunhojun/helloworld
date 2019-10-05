#include "Card.h"
#include "DeckOfCards.h"
#include <iostream>
using namespace std;

int main() {
	DeckOfCards deck_A;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cout << deck_A.dealCards().toString() << endl;
		}
		cout << endl;
	}

	deck_A.shuffle();
	cout << "---------------------------" << endl;
	cout << "After Shuffle" << endl;
	cout << "---------------------------" << endl;
	
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cout << deck_A.dealCards().toString() << endl;
		}
		cout << endl;
	}
}