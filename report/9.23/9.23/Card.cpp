#include "Card.h"
Card::Card() {

};

Card::Card(int face_val, int suit_val)
:face(face_val)
{
	switch (suit_val)
	{
	case 0:suit = "Spades";
		break;
	case 1:suit = "Diamonds";
		break;
	case 2:suit = "Hearts";
		break;
	case 3:	suit = "Clubs";
		break;
	default:
		throw;
	}
}

std::string Card::toString() {
	std::string face_string;

	switch (face)
	{
	case 0:face_string = "Ace";
		break;
	case 1:face_string = "Two";
		break;
	case 2:face_string = "Three";
		break;
	case 3:face_string = "Four";
		break;
	case 4:face_string = "Five";
		break;
	case 5:face_string = "Six";
		break;
	case 6:face_string = "Seven";
		break;
	case 7:face_string = "Eight";
		break;
	case 8:face_string = "Nine";
		break;
	case 9:face_string = "Ten";
		break;
	case 10:face_string = "Jack";
		break;
	case 11:face_string = "Queen";
		break;
	case 12:face_string = "King";
		break;
	default:
		break;
	}

	return face_string + " of " + suit + " ";
}