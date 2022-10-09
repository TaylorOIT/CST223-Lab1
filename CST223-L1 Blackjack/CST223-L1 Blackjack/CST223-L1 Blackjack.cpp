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
using std::cout;
using std::endl;

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


void drawCard(vector< tuple <string, string, int> > &deck, vector< tuple <string, string, int> > &hand)
{
	hand.push_back(deck[0]);
	deck.erase(deck.begin());
}
// draws a card for the player and deletes a card from the top of the deck

int sumHand(vector< tuple <string, string, int> > hand)
{
	int handsum{};
	for (auto h: hand)
	{
		handsum += get<2>(h);
	}
	return handsum;
}
// returns the cards total value based on their hand

bool handBust(int total)
{
	if (total > 21)
		return true;
	else
		return false;
}
// returns a bool to represent if the hand busts

bool handWin(int total)
{
	if (total == 21)
		return true;
	else
		return false;
}
// returns a bool to represent if the hand wins

void showHand(vector< tuple <string, string, int> > hand)
{
	cout << "Players Hand: ";

	for (auto h : hand) 
	{
		cout << get<0>(h) << get<1>(h) << " ";
	}
	
	cout << endl;
	cout << "Hand Total: " << sumHand(hand) << endl;
}
// shows the players hand

int main()
{
	vector< tuple <string, string, int> > deck{};
	deck = createDeck();

	vector< tuple <string, string, int> > dealershand;
	vector< tuple <string, string, int> > playershand;
	char choice{};
	bool bust{};
	bool win{};

	drawCard(deck, dealershand);
	drawCard(deck, dealershand);
	drawCard(deck, playershand);
	drawCard(deck, playershand);
	// dealing the hands

	cout << "Welcome to Blackjack!" << endl;
	cout << "---------------------" << endl;
	
	cout << "Dealers Hand: " << get<0>(dealershand[0]) << get<1>(dealershand[0]) << " ?? \n";
	cout << "Hand Total: " << get<2>(dealershand[0]) << endl << endl;

	cout << "Players Hand: " << get<0>(playershand[0]) << get<1>(playershand[0]);
	cout << " " << get<0>(playershand[1]) << get<1>(playershand[1]) << endl;
	cout << "Hand Total: " << sumHand(playershand) << endl;

	while (choice != 's' && bust != true && win != true) 
	{
		cout << "Would you like to hit/stand (h/s)?: ";
		std::cin >> choice;

		if (choice == 'h')
		{
			drawCard(deck, playershand);

			showHand(playershand);

			bust = handBust(sumHand(playershand));
			win = handWin(sumHand(playershand));
		}
	}

	

	//for (auto p : playershand) 
	//{
	//	std::cout << "Card: " << get<0>(p) << get<1>(p) << " Value: " << get<2>(p) << "\n";
	//}

	//std::cout << "Sum: " << sumHand(playershand);
}

