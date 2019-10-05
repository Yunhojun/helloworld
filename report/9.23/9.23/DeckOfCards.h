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


//DeckOfCard  Ŭ����
//a Cards�� �����ϴ� deck�̶�� �̸��� �迭 �����
//b ���� ī�带 �ٷ�?(next card to deal?) currentCard��� �̸��� ���� �����
//c deck�� �ִ� Cards�� ī�带 �ʱ�ȭ�ϴ� ������ �����
//d deck�� Cards�� ���� shuffle�Լ��� �����/ Cards�� �迭�� ���� �������� ������ �� Card�� �ٲٴ� �˰���
//e deck���� ���� Card�� �����ϴ� dealCard�Լ�
//f �� deal�� ī�尡 �ִ��� Ȯ���ϴ� moreCard�Լ�