#include "DeckOfCards.h"

DeckOfCards::DeckOfCards() {
	currenCard = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[currenCard] = Card(j, i);
			currenCard++;
		}
	}
}

void DeckOfCards::shuffle() {
	srand(time(0));
	for (int i = 0; i < 100; i++) {
		int first = rand() % 52;
		int second = rand() % 52;
		Card temp = deck[first];
		deck[first] = deck[second];
		deck[second] = temp;
	}
	currenCard = 52;

}

Card DeckOfCards::dealCards() {
	Card CardtoDeal = deck[52 - currenCard];
	currenCard--;
	return CardtoDeal;
}

bool DeckOfCards::moreCard() {
	if (currenCard > 0) {
		return true;
	}
	else {
		return false;
	}
}