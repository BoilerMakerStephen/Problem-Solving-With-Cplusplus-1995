//Problem Solving With C++ - Walter Savitch
//Chapter 9
//Programming Project #7
//SCORE A POKER HAND

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>

using namespace std;

struct Card {
	int val;
	string suit;
};

//Main menu
void menu();

//Initialize struct array
void sorted_deck(Card deck[]);

//Print five random cards
void print_hand(Card deck[], Card hand[]);

//Swaps structs
void swap(Card arr_1[], Card arr_2[]);

//Sorts hand
void sort_hand(Card hand[]);

//Score hand
void score_hand(Card hand[]);

//royal flush
bool score_suit(Card hand[]);

//royal flush
bool score_val(Card hand[]);

//royal flush
bool score_royal_flush(Card hand[]);

//straight flush
bool score_suit_straight_flush(Card hand[]);

//straight flush
bool score_val_straight_flush(Card hand[]);

//straight flush
bool score_straight_flush(Card hand[]);

//four of a kind
bool score_first_four(Card hand[]);

//four of a kind
bool score_last_four(Card hand[]);

//four of a kind
bool score_four(Card hand[]);

//full house
bool score_first_three(Card hand[]);

//full house
bool score_last_three(Card hand[]);

//full house
bool score_full_house(Card hand[]);

//flush
bool score_flush(Card hand[]);

//straight
bool score_straight(Card hand[]);

//three of a find
bool score_three_kind(Card hand[]);

//two pair
bool score_two_pair(Card hand[]);

//one pair
bool score_one_pair(Card hand[]);

//format header
void format();

//main function
void play_hand(Card hand[], Card deck[]);

int main() {

	Card deck[52], hand[5];
		
	play_hand(hand, deck);

	
}

//Main menu
void menu() {
	do {
		system("CLS");
		cout << setw(20) << "SCORE POKER HAND" << endl;
		cout << setfill('-') << setw(40) << '-' << endl;
		cout << setfill('\0');
		cout << "1 = Ace" << endl;
		cout << "2 = 2" << endl;
		cout << "3 = 3" << endl;
		cout << "4 = 4" << endl;
		cout << "5 = 5" << endl;
		cout << "6 = 6" << endl;
		cout << "7 = 7" << endl;
		cout << "8 = 8" << endl;
		cout << "9 = 9" << endl;
		cout << "10 = 10" << endl;
		cout << "11 = Jack" << endl;
		cout << "12 = Queen" << endl;
		cout << "13 = King" << endl;
		cout << endl;
		cout << "Press any key to continue..." << endl;
	} while (!_getch());

	do {
		system("CLS");
		cout << setw(20) << "POKER HANDS" << endl;
		cout << setfill('-') << setw(40) << '-' << endl;
		cout << setfill('\0');
		cout << "ROYAL FLUSH: 10, 11, 12, 13, 1 of the same suit" << endl;
		cout << "STRAIGHT FLUSH: i.e., 5, 6, 7, 8, 9 of the same suit" << endl;
		cout << "FOUR OF A KIND: i.e., 1, 1, 1, 1, 2" << endl;
		cout << "FULL HOUSE: i.e., 1, 1, 1, 13, 13" << endl;
		cout << "FLUSH: i.e., 2, 4, 6, 8, 13 of the same suit" << endl;
		cout << "STRAIGHT: i.e., 5, 6, 7, 8, 9 not of the same suit" << endl;
		cout << "THREE OF A KIND: i.e., 1, 1, 1, 2, 3" << endl;
		cout << "PAIR: i.e., 1, 1, 2, 3, 4" << endl;
		cout << endl;
		cout << "Press any key to continue..." << endl;
	} while (!_getch());
}

//Initialize struct array
void sorted_deck(Card deck[])
{
	for (int i = 0; i < 52; i++) 
	{
		if (i <= 12) 
		{			
			deck[i].suit = "clubs";
			deck[i].val = i + 1;
		}
		else if (i <= 25)
		{		
			deck[i].suit = "diamonds";
			deck[i].val = i - 12;
		}
		else if (i <= 38)
		{		
			deck[i].suit = "spades";
			deck[i].val = i - 25;
		}
		else
		{					
			deck[i].suit = "hearts";
			deck[i].val = i -38;
		}
	}

	return;
}

//Print five random cards
void print_hand(Card deck[], Card hand[])
{
	int temp[5], n;
	for (int i = 0; i < 5; i++)
	{
		bool check;
		do 
		{
			n = rand() % 51 + 0;
			check = true;
			for (int j = 0; j < i; j++)
			{
				if (n == temp[j]) 
				{
					check = false;
					break;
				}
			}
		} while (!check);

		hand[i].val = deck[n].val;
		hand[i].suit = deck[n].suit;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << hand[i].val << " " << hand[i].suit << endl;
	}

	return;
}

//Swaps structs
void swap(Card arr_1[], Card arr_2[])
{
	Card temp;
	temp = arr_1[5];
	arr_1[5] = arr_2[5];
	arr_2[5] = temp;

	return;
}

//Sorts hand
void sort_hand(Card hand[])
{
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++) {
			if (hand[j].val < hand[j + 1].val) {
				swap(hand[j], hand[j + 1]);
			}
		}
	}
	
	cout << "Sorted hand" << endl;
	cout << setfill('-') << setw(10) << '-' << endl;
	cout << setfill('\0');
	
	for (int i = 0; i < 5; i++)
	{
		cout << hand[i].val << " " << hand[i].suit << endl;
	}

	return;
}

//Score hand
void score_hand(Card hand[]) 
{
	if (score_royal_flush(hand) == true)
	{
		cout << "Four of a kind" << endl;
	}
	else if (score_straight_flush(hand) == true)
	{
		cout << "Straight" << endl;
	}
	else if (score_four(hand) == true)
	{
		cout << "Flush" << endl;
	}
	else if (score_full_house(hand) == true)
	{
		cout << "Full house" << endl;
	}
	else if (score_flush(hand) == true)
	{
		cout << "Royal flush" << endl;
	}
	else if (score_straight(hand) == true)
	{
		cout << "Straight flush" << endl;
	}
	else if (score_three_kind(hand) == true)
	{
		cout << "Three of a kind" << endl;
	}
	else if (score_two_pair(hand) == true)
	{
		cout << "Two pair" << endl;
	}
	else if (score_one_pair(hand) == true)
	{
		cout << "One pair" << endl;
	}
	else
	{
		cout << "Nothing" << endl;
	}

	return;
}

//royal flush
bool score_royal_flush(Card hand[])
{
	if (score_suit(hand) == true && score_val(hand) == true)
		return true;
	else
		return false;
}

//royal flush
bool score_suit(Card hand[])
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (hand[i].suit == hand[i + 1].suit)
			count++;
	}
	if (count == 4)
		return true;
	else
		return false;
}

//royal flush
bool score_val(Card hand[])
{
	int count = 0, num = 13;
	for (int i = 0; i < 4; i++)
	{
		if (hand[i].val == num)
		{
			count++;
			num--;
		}
	}
	if (count == 4 && hand[4].val == 1)
		return true;
	else
		return false;
}

//straight flush
bool score_suit_straight_flush(Card hand[])
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (hand[i].suit == hand[i + 1].suit)
			count++;
	}
	if (count == 4)
		return true;
	else
		return false;
}

//straight flush
bool score_val_straight_flush(Card hand[])
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if ((hand[i].val - hand[i + 1].val) == 1)
			count++;
	}
	if (count == 4)
		return true;
	else
		return false;
}

//straight flush
bool score_straight_flush(Card hand[])
{
	if (score_suit(hand) == true && score_val(hand) == true)
		return true;
	else
		return false;
}

//four of a kind
bool score_first_four(Card hand[])
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (hand[0].val == hand[i + 1].val)
			count++;
	}
	if (count == 3)
		return true;
	else
		return false;
}

//four of a kind
bool score_last_four(Card hand[])
{
	int count = 0;
	for (int i = 1; i < 5; i++)
	{
		if (hand[1].val == hand[i + 1].val)
			count++;
	}
	if (count == 3)
		return true;
	else
		return false;
}

//four of a kind
bool score_four(Card hand[])
{
	if (score_first_four(hand) == true || score_last_four(hand) == true)
		return true;
	else
		return false;

}

//full house
bool score_first_three(Card hand[])
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (hand[0].val == hand[i + 1].val)
			count++;
	}
	if (hand[3].val == hand[4].val)
		count++;
	if (count == 3)
		return true;
	else
		return false;
}

//full house
bool score_last_three(Card hand[])
{
	int count = 0;
	for (int i = 2; i < 5; i++)
	{
		if (hand[2].val == hand[i + 1].val)
			count++;
	}
	if (hand[0].val == hand[1].val)
		count++;
	if (count == 3)
		return true;
	else
		return false;
}

//full house
bool score_full_house(Card hand[])
{
	if (score_first_three(hand) == true || score_last_three(hand) == true)
		return true;
	else
		return false;
}

//flush
bool score_flush(Card hand[])
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (hand[i].suit == hand[i + 1].suit)
			count++;
	}
	if (count == 4)
		return true;
	else
		return false;
}

//straight
bool score_straight(Card hand[])
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (hand[i].val - hand[i + 1].val == 1)
			count++;
	}
	if (count == 4)
		return true;
	else
		return false;
}

//three of a kind
bool score_three_kind(Card hand[])
{
	bool found = false;

	if (hand[0].val == hand[1].val && hand[1].val == hand[2].val)
	{
		found = true;
	}
	else if (hand[1].val == hand[2].val && hand[1].val == hand[3].val)
	{
		found = true;
	}
	else if (hand[2].val == hand[3].val && hand[2].val == hand[4].val)
	{
		found = true;
	}

	if (found)
		return true;
	else
		return false;
}

//two pair
bool score_two_pair(Card hand[])
{
	bool found = false;
	
	if (hand[0].val == hand[1].val && hand[2].val == hand[3].val)
	{
		found = true;
	}
	else if (hand[1].val == hand[2].val && hand[3].val == hand[4].val)
	{
		found = true;
	}

	if (found)
		return true;
	else
		return false;
}

//one pair
bool score_one_pair(Card hand[])
{
	bool found = false;

	if (hand[0].val == hand[1].val || hand[1].val == hand[2].val ||
		hand[2].val == hand[3].val || hand[3].val == hand[4].val)
	{
		found = true;
	}
	
	if (found)
		return true;
	else
		return false;
}

void format()
{
	system("CLS");
	cout << "Poker Hand" << endl;
	cout << setfill('-') << setw(10) << '-' << endl;
	cout << setfill('\0');

	return;
}

void play_hand(Card hand[], Card deck[])
{
	char ans;
	
	//Seed random number generator
	srand(time(NULL));

	//Initialize struct deck
	sorted_deck(deck);

	//Output menu
	menu();

	do{
		format();
		print_hand(deck, hand);
		cout << endl;
		sort_hand(hand);
		score_hand(hand);
		cout << "Again? (Y/N)" << endl;
		cin >> ans;
	} while (ans == 'Y' || ans == 'y');
}





