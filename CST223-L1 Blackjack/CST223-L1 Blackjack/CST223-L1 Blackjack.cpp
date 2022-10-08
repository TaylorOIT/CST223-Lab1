// Taylor Boyd, CST223 lab 1
// Blackjack

#include <iostream>
#include <vector>
#include <tuple>

using std::vector;
using std::string;
using std::tuple;

vector< tuple <string, string, int> > createDeck()
{
	string cardfaces[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "King", "Jack", "Queen" };
	string cardsuits[4] = { "Diamonds", "Clubs", "Hearts", "Spades" };
	int cardvalues[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

	vector< tuple <string, string, int> > Deck;
	// includes the cardface, cardsuit, and value of the card in blackjack

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 13; i++)
		{
			Deck.push_back(std::make_tuple(cardfaces[i], cardsuits[j], cardvalues[i]));
		}
	}

	return Deck;
}
// creates a deck of cards in the form of a vector of tuples

int main()
{
	vector< tuple <string, string, int> > Deck;
	// includes the cardface, cardsuit, and value of the card in blackjack

	Deck = createDeck();

	std::cout << std::get<0>(Deck[13]) << " " << std::get<1>(Deck[13]) << " " << std::get<2>(Deck[13]);

}

