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

void showHand(vector< tuple <string, string, int> > hand, string playersname)
{
	cout << playersname << " Hand: ";

	for (auto h : hand) 
	{
		cout << get<0>(h) << get<1>(h) << " ";
	}
	
	cout << endl;
	cout << "Hand Total: " << sumHand(hand) << endl;
}
// shows the players hand

void showResult(int playerstotal, int dealerstotal)
{
	if (playerstotal > dealerstotal)
	{
		cout << "\nPlayer has a closer hand to 21. Player wins!";
	}
	else if (playerstotal < dealerstotal)
	{
		cout << "\nDealer has a closer hand to 21. Dealer wins!";
	}
	else
		cout << "\nThere was a tie! Nobody wins :{";
}
// shows the results of the game if nobody has hit blackjack or busted


void aceCheck(vector< tuple <string, string, int> > &hand) 
{	
	if (sumHand(hand) > 21)
	{
		for (int i = 0; i < hand.size(); i++)
		{
			if (get<0>(hand.at(i)) == "A") 
			{
				hand.push_back(std::make_tuple(get<0>(hand.at(i)), get<1>(hand.at(i)), 1));
				hand.erase(hand.begin()+i);
			}
		}
	}
}
// if the players hand is a bust and they have an ace in their hand, change the ace value from 11 to 1

int main()
{
	char choice{};
	do 
	{
		bool winner{};
		vector< tuple <string, string, int> > deck{};
		deck = createDeck();

		vector< tuple <string, string, int> > dealershand;
		vector< tuple <string, string, int> > playershand;
		char hitorstand{};

		drawCard(deck, dealershand);
		drawCard(deck, dealershand);
		drawCard(deck, playershand);
		drawCard(deck, playershand);
		// dealing the hands

		cout << "Welcome to Blackjack!" << endl;
		cout << "---------------------" << endl;

		cout << "Dealers Hand: " << get<0>(dealershand[0]) << get<1>(dealershand[0]) << " ?? \n";
		cout << "Hand Total: " << get<2>(dealershand[0]) << endl << endl;

		showHand(playershand, "Players");

		while (hitorstand != 's' && sumHand(playershand) < 21)
		{
			cout << "Would you like to hit/stand (h/s)?: ";
			std::cin >> hitorstand;

			if (hitorstand == 'h')
			{
				drawCard(deck, playershand);
				aceCheck(playershand);
				showHand(playershand, "Players");
			}
			else continue;
		}

		if (sumHand(playershand) > 21)
		{
			cout << "\nPlayer has busted! Dealer wins!\n";
			showHand(dealershand, "Dealers");
			winner = true;
		}
		else if (sumHand(playershand) == 21)
		{
			cout << "\nPlayer has blackjack! Player wins!\n";
			showHand(dealershand, "Dealers");
			winner = true;
		}
		else if (sumHand(dealershand) == 21)
		{
			cout << "\nDealer has blackjack! Dealer wins!\n";
			showHand(dealershand, "Dealers");
			winner = true;
		}

		cout << endl;

		if ((sumHand(dealershand) < sumHand(playershand)) && winner != true)
		{
			while (sumHand(dealershand) < sumHand(playershand))
			{
				drawCard(deck, dealershand);
				aceCheck(dealershand);
				cout << "Dealer has hit: " << endl;
				showHand(dealershand, "Dealers");
				cout << endl;
			}
			// dealer will hit until they get a better hand than the player or hit blackjack
		}
		
		if (sumHand(dealershand) > 21)
		{
			cout << "\nDealer has busted! Player wins!";
			winner = true;
		}
		else if (sumHand(dealershand) == 21 && winner != true)
		{
			cout << "\nDealer has blackjack! Dealer wins!";
			winner = true;
		}

		if (winner != true)
		{
			showHand(dealershand, "Dealers");
			showHand(playershand, "Players");

			showResult(sumHand(playershand), sumHand(dealershand));
		}

		cout << endl << "Would you like to play again? (y/n): ";
		std::cin >> choice;
		system("cls");
		// clearing the cmd window for the next game
	} while (choice != 'n');

}

