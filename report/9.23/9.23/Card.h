#include <string>
#ifndef CARD_H
#define CARD_H

class Card {
public:
	Card();
	Card(int, int);
	std::string toString();

private:
	int face;//1~13
	std::string suit;//spade diamond heart club
};


#endif // !CARD_H

//CardŬ����
//a ������ ��� faces ����, suits �׸� ����������
//b ���� �ʱ�ȭ�ϴ� ������ �����
//c ����ƽ ��Ʈ�� �迭�� face�� suit ǥ��
//d toString �Լ��� �̿��Ͽ�  Card�� "face of suit"�� ���·� �����ϱ�