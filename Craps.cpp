/*Written By Amin Abrishami Spring 2020
  Have Fun (; and Stay at Home 
  Compiled And Run With Microsoft Visual Studio and MinGW
							*/
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int rollDice();
int main()
{
enum Status {WON,LOST,CONTINUE};
	Status gameStatus;
	int myPoint, sum;
	
	int quit = 1;
	while (quit == 1)
	{
		system("cls");
		srand(time(NULL));
		sum = rollDice();
		switch (sum)
		{
		case 2:
		case 3:
		case 12:
			gameStatus = WON;
			break;
		case 7:
		case 11:
			gameStatus = LOST;
			break;
		default:
			gameStatus = CONTINUE;
			myPoint = sum;
			cout << "Your Point is : " << myPoint << endl;
			break;
		}

		while (gameStatus == CONTINUE)
		{
			sum = rollDice();
			if (sum == 7)
				gameStatus = LOST;
			else
			{
				if (sum == myPoint)
					gameStatus = WON;
			}

		}

		if (gameStatus == WON)
			cout << "The Player wins" << endl;
		if (gameStatus == LOST)
			cout << "The Player loses" << endl;

		cout << "Would you like to Continue? (if Yes Press 1 and No Press 0): " ;
		cin >> quit;


	}
	return 0;
}

int rollDice()
{
	int die1, die2, sum;
	die1 = rand() % 6 + 1;
	die2 = rand() % 6 + 1;
	sum = die1 + die2;
	cout << "Roll(1)  " << die1 << "  +  " <<"Roll(2)  " <<die2<<"  is  : " << sum << endl;
	return sum;
}