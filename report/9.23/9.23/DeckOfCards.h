#include "Card.h"
#include <random>
#include <ctime>
#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

class DeckOfCards {
public:
	DeckOfCards();
	void shuffle();
	Card dealCards();
	bool moreCard();

private:
	Card deck[52];
	int currenCard;
};

#endif // !DECKOFCARDS_H


//DeckOfCard  클래스
//a Cards를 저장하는 deck이라는 이름의 배열 만들기
//b 다음 카드를 다룰?(next card to deal?) currentCard라는 이름의 정수 만들기
//c deck에 있는 Cards에 카드를 초기화하는 생성자 만들기
//d deck에 Cards를 섞는 shuffle함수를 만들기/ Cards의 배열을 에서 랜덤으로 선택한 두 Card를 바꾸는 알고리즘
//e deck에서 다음 Card를 리턴하는 dealCard함수
//f 더 deal할 카드가 있는지 확인하는 moreCard함수