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

//Card클래스
//a 데이터 멤버 faces 숫자, suits 그림 열거형으로
//b 둘을 초기화하는 생성자 만들기
//c 스태틱 스트링 배열로 face랑 suit 표현
//d toString 함수를 이용하여  Card를 "face of suit"의 형태로 리턴하기