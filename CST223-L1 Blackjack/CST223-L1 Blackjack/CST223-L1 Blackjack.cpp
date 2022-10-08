// Taylor Boyd, CST223 lab 1
// Blackjack

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <random>

using std::vector;
using std::string;
using std::tuple;

vector< tuple <string, string, int> > createDeck()
{
	string cardfaces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "K", "J", "Q" };
	string cardsuits[4] = { "D", "C", "H", "S" };
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
	vector< tuple <string, string, int> > deck;
	deck = createDeck();

	std::mt19937 rand{ std::random_device{}() };
	std::shuffle(deck.begin(), deck.end(), rand);
	// shuffles the deck

	for (auto d : deck) 
	{
		std::cout << "Card: " << std::get<0>(d) << std::get<1>(d) << " Value: " << std::get<2>(d) << "\n";
	}

}

