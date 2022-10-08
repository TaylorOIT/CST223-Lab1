// Taylor Boyd, CST223 lab 1
// Blackjack

#include <iostream>
#include <vector>
#include <tuple>
#include <random>

using std::vector;
using std::string;
using std::tuple;
using std::get;

vector< tuple <string, string, int> > createDeck()
{
	string cardfaces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "K", "J", "Q" };
	string cardsuits[4] = { "D", "C", "H", "S" };
	int cardvalues[13] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

	vector< tuple <string, string, int> > deck;
	// includes the cardface, cardsuit, and value of the card in blackjack

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 13; i++)
		{
			deck.push_back(std::make_tuple(cardfaces[i], cardsuits[j], cardvalues[i]));
		}
	}

	std::mt19937 rand{ std::random_device{}() };
	std::shuffle(deck.begin(), deck.end(), rand);
	// shuffles the deck

	return deck;
}
// creates a deck of cards in the form of a vector of tuples that is shuffled


vector< tuple <string, string, int> > drawCard(vector< tuple <string, string, int> > &deck, vector< tuple <string, string, int> > &hand)
{
	hand.push_back(deck[0]);
	deck.erase(deck.begin());
	return hand;
}
// draws a card for the player and deletes a card from the top of the deck

int sumHand(vector< tuple <string, string, int> >& hand)
{
	int handsum{};
	for (auto h: hand)
	{
		handsum += get<2>(h);
	}
	return handsum;
}
// adds the cards in the players hand based on their value

int main()
{
	vector< tuple <string, string, int> > deck{};
	deck = createDeck();

	vector< tuple <string, string, int> > dealershand;
	vector< tuple <string, string, int> > playershand;

	drawCard(deck, dealershand);
	drawCard(deck, dealershand);
	drawCard(deck, playershand);
	drawCard(deck, playershand);
	// dealing the hands

	for (auto p : playershand) 
	{
		std::cout << "Card: " << get<0>(p) << get<1>(p) << " Value: " << get<2>(p) << "\n";
	}

	std::cout << "Sum: " << sumHand(playershand);
}

