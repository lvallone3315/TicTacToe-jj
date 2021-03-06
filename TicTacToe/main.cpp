//Coded by Jeffrey, Robert, and Michael. Initial code was started Thursday night, beginning with the pre-plan process and psuedocode. 
//Code was finished and ready for final revisions by QA on Monday at 12 p.m.

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <array>
using namespace std;

//Initialization of Variables that are used throughout the entire program
static string line1 = "?  ?  ?";
static string line2 = "?  ?  ?";
static string line3 = "?  ?  ?";
static string player1Indicator = "X"; //Assigned "X" to player one 
static string player2Indicator = "O"; //Asssigned "O" to player two
static double moveInput;
static int moves[9];

//Method used for checking valid moves, making sure no duplicate moves and no numbers greater than 9 or less than 1
int checkValidMove(int num)
{
	int check = 1;
	int check1 = 1;
	if (num > 9 || num < 1) //User input validation
	{
		while (check != 0)
		{
			if (num > 9 || num < 1)
			{
				system("CLS");
				cout << line1 << endl << line2 << endl << line3 << endl;
				cout << "Invalid Move at space: " << num << " . Please Enter a Valid Move (1 = Top Left , 9 = Bottom Right)" << endl;
				cin >> num;
			}
			if (num <= 9 && num >= 1)
			{
				check--;
				moveInput = num;
			}
		}
	}
	while (check1 != 0)
	{
		for (int i = 0; i < 9; i++)
		{
			if (num == moves[i])
			{
				system("CLS");
				cout << line1 << endl << line2 << endl << line3 << endl;
				cout << "That Move Has Already Been Made: " << num << ", Please Make A Different Move (1 = Top Left , 9 = Bottom Right)" << endl;
				cin >> num;
				i--;
			}
		}
		while (check1 != 0)
		{
			if (num > 9 || num < 1)
			{
				system("CLS");
				cout << line1 << endl << line2 << endl << line3 << endl;
				cout << "Invalid Move at space: " << num << " . Please Enter a Valid Move (1 = Top Left , 9 = Bottom Right)" << endl;
				cin >> num;
			}
			if (num <= 9 && num >= 1)
			{
				moveInput = num;
				check1--;
				return num;
			}
		}
	}
}
//Method to have the Player 1 Move change the string and display correctly
void makeMovePlayer1(int spot)
{
	if (spot == 1)
	{
		line1.replace(0, 1, player1Indicator);
	}
	if (spot == 2)
	{
		line1.replace(3, 1, player1Indicator);
	}
	if (spot == 3)
	{
		line1.replace(6, 1, player1Indicator);
	}
	if (spot == 4)
	{
		line2.replace(0, 1, player1Indicator);
	}
	if (spot == 5)
	{
		line2.replace(3, 1, player1Indicator);
	}
	if (spot == 6)
	{
		line2.replace(6, 1, player1Indicator);
	}
	if (spot == 7)
	{
		line3.replace(0, 1, player1Indicator);
	}
	if (spot == 8)
	{
		line3.replace(3, 1, player1Indicator);
	}
	if (spot == 9)
	{
		line3.replace(6, 1, player1Indicator);
	}
}
//Method to have the Player 2 Move change the string and display correctly
void makeMovePlayer2(int spot)
{
	if (spot == 1)
	{
		line1.replace(0, 1, player2Indicator);
	}
	if (spot == 2)
	{
		line1.replace(3, 1, player2Indicator);
	}
	if (spot == 3)
	{
		line1.replace(6, 1, player2Indicator);
	}
	if (spot == 4)
	{
		line2.replace(0, 1, player2Indicator);
	}
	if (spot == 5)
	{
		line2.replace(3, 1, player2Indicator);
	}
	if (spot == 6)
	{
		line2.replace(6, 1, player2Indicator);
	}
	if (spot == 7)
	{
		line3.replace(0, 1, player2Indicator);
	}
	if (spot == 8)
	{
		line3.replace(3, 1, player2Indicator);
	}
	if (spot == 9)
	{
		line3.replace(6, 1, player2Indicator);
	}
}
//Method to check to see if Player 1 has won the game with a match 3
//This function checks all 8 possibilities for player 1 to win (3 horizontal, 3 vertical, 2 diagonal)
bool checkWinPlayer1()
{
	if (line1 == "X  X  X")
	{
		return true;
	}
	if (line2 == "X  X  X")
	{
		return true;
	}
	if (line3 == "X  X  X")
	{
		return true;
	}
	if (line1.substr(0,1) == "X") //Testing comment
	{
		if (line2.substr(0, 1) == "X")
		{
			if (line3.substr(0, 1) == "X")
			{
				return true;
			}
		}
	}
	if (line1.substr(3, 1) == "X")
	{
		if (line2.substr(3, 1) == "X")
		{
			if (line3.substr(3, 1) == "X")
			{
				return true;
			}
		}
	}
	if (line1.substr(6, 1) == "X")
	{
		if (line2.substr(6, 1) == "X")
		{
			if (line3.substr(6, 1) == "X")
			{
				return true;
			}
		}
	}
	if (line1.substr(0, 1) == "X")
	{
		if (line2.substr(3, 1) == "X")
		{
			if (line3.substr(6, 1) == "X")
			{
				return true;
			}
		}
	}
	if (line1.substr(6, 1) == "X")
	{
		if (line2.substr(3, 1) == "X")
		{
			if (line3.substr(0, 1) == "X")
			{
				return true;
			}
		}
	}
	return false;
}
//Method to check to see if Player 2 has won the game with a match 3
//This function checks all 8 possibilities for player 2 to win (3 horizontal, 3 vertical, 2 diagonal)
bool checkWinPlayer2()
{
	if (line1 == "O  O  O")
	{
		return true;
	}
	if (line2 == "O  O  O")
	{
		return true;
	}
	if (line3 == "O  O  O")
	{
		return true;
	}
	if (line1.substr(0, 1) == "O")
	{
		if (line2.substr(0, 1) == "O")
		{
			if (line3.substr(0, 1) == "O")
			{
				return true;
			}
		}
	}
	if (line1.substr(3, 1) == "O")
	{
		if (line2.substr(3, 1) == "O")
		{
			if (line3.substr(3, 1) == "O")
			{
				return true;
			}
		}
	}
	if (line1.substr(6, 1) == "O")
	{
		if (line2.substr(6, 1) == "O")
		{
			if (line3.substr(6, 1) == "O")
			{
				return true;
			}
		}
	}
	if (line1.substr(0, 1) == "O")
	{
		if (line2.substr(3, 1) == "O")
		{
			if (line3.substr(6, 1) == "O")
			{
				return true;
			}
		}
	}
	if (line1.substr(6, 1) == "O")
	{
		if (line2.substr(3, 1) == "O")
		{
			if (line3.substr(0, 1) == "O")
			{
				return true;
			}
		}
	}
	return false;
}


int main()
{
	//Initialzation of variables including our random number generator
	int firstPlay, turnCount = 0, moveCount = 0;
	srand(time(0));
	//Generates either 1 or 2 , 1 = Player 1 goes first and 2 = Player 2 goes first.
	firstPlay = (rand() % 2) + 1;
	//If statement for Player 1 Going First.
	if (firstPlay == 1)
	{
		cout << "Player 1 Goes First" << endl;
		//While loop to have the turns constantly go, max amount of turns in a game is 8 so this loop will have each player go 4 times before ending.
		while (turnCount != 4)
		{
			cout << "Player 1 (X), Select a Number 1-9 To Select Your Move. (Please read from left to right where top left = 1 and bottom right = 9)" << endl;
			cout << line1 << endl << line2 << endl << line3 << endl;
			cin >> moveInput;
			//Checks input to see if it is a number or a string , if the input is a string the program will ask for reinput.
			while (!cin >> (int)moveInput) 
			{
				cout << "INVALID INPUT." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Player 1 (X), Select a Number 1-9 To Select Your Move. (Top Left = 1 and Bottom Right = 9)" << endl;
				cout << line1 << endl << line2 << endl << line3 << endl;
				cin >> moveInput;
			}
			//Calls the validmove method to check if the move is valid or not.
			checkValidMove(moveInput);
			//Places the move selected into an array for input validation in the validmove method.
			moves[moveCount] = moveInput;
			moveCount++;
			//After the validation the move for Player 1 is made
			makeMovePlayer1(moveInput);
			//Checks to see if Player 1 has won off of his turn before moving onto player 2
			if (checkWinPlayer1())
			{
				system("CLS");
				cout << line1 << endl << line2 << endl << line3 << endl;
				cout << "Player 1 Wins!" << endl;
				system("pause");
				return 0;
			}		
			//Increment of the turn count so it ends on the 8th move.
			turnCount++;
			cout << endl;
			//This is the same thing has above but for Player 2.
			cout << "Player 2 (O), Select a Number 1-9 To Select Your Move. (Please read from left to right where top left = 1 and bottom right = 9)" << endl;
			cout << line1 << endl << line2 << endl << line3 << endl;
			cin >> moveInput;
			while (!cin >> (int)moveInput) 
			{
				cout << "INVALID INPUT." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Player 2 (O), Select a Number 1-9 To Select Your Move. (Top Left = 1 and Bottom Right = 9)" << endl;
				cout << line1 << endl << line2 << endl << line3 << endl;
				cin >> moveInput;
			}
			checkValidMove(moveInput);
			moves[moveCount] = moveInput;
			moveCount++;
			makeMovePlayer2(moveInput);
			if (checkWinPlayer2())
			{
				system("CLS");
				cout << line1 << endl << line2 << endl << line3 << endl;
				cout << "Player 2 Wins!" << endl;
				system("pause");
				return 0;
			}
			cout << endl;
			
		}
		//After the loop ends the last 9th turn is made.
		cout << "Player 1 (X), Select a Number 1-9 To Select Your Move. (Please read from left to right where top left = 1 and bottom right = 9)" << endl;
		cout << line1 << endl << line2 << endl << line3 << endl;
		cin >> moveInput;
		while (!cin >> (int)moveInput) 
		{
			cout << "INVALID INPUT." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Player 1 (X), Select a Number 1-9 To Select Your Move. (Top Left = 1 and Bottom Right = 9)" << endl;
			cout << line1 << endl << line2 << endl << line3 << endl;
			cin >> moveInput;
		}
		checkValidMove(moveInput);
		moves[moveCount] = moveInput;
		moveCount++;
		makeMovePlayer1(moveInput);
		if (checkWinPlayer1())
		{
			system("CLS");
			cout << line1 << endl << line2 << endl << line3 << endl;
			cout << "Player 1 Wins!" << endl;
			system("pause");
			return 0;
		}
		//If no winner is declared from the checkwin method always returning false, the game ends in a draw.
		system("CLS");
		cout << line1 << endl << line2 << endl << line3 << endl;
		cout << "The Game ends in a Draw!" << endl;
		cout << endl;		
	}
	//Same code as above, but in the case Player 2 gets to play first.
	if (firstPlay == 2)
	{
		cout << "Player 2 Goes First" << endl;
		while (turnCount != 4)
		{
			cout << "Player 2 (O), Select a Number 1-9 To Select Your Move. (Please read from left to right where top left = 1 and bottom right = 9)" << endl;
			cout << line1 << endl << line2 << endl << line3 << endl;
			cin >> moveInput;
			while (!cin >> (int)moveInput) 
			{
				cout << "INVALID INPUT." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Player 2 (O), Select a Number 1-9 To Select Your Move. (Top Left = 1 and Bottom Right = 9)" << endl;
				cout << line1 << endl << line2 << endl << line3 << endl;
				cin >> moveInput;
			}
			checkValidMove(moveInput);
			moves[moveCount] = moveInput;
			moveCount++;
			makeMovePlayer2(moveInput);
			if (checkWinPlayer2())
			{
				system("CLS");
				cout << line1 << endl << line2 << endl << line3 << endl;
				cout << "Player 2 Wins!" << endl;
				system("pause");
				return 0;
			}
			turnCount++;
			cout << endl;
			cout << "Player 1 (X), Select a Number 1-9 To Select Your Move. (Please read from left to right where top left = 1 and bottom right = 9)" << endl;
			cout << line1 << endl << line2 << endl << line3 << endl;
			cin >> moveInput;
			while (!cin >> (int)moveInput) 
			{
				cout << "INVALID INPUT." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Player 1 (X), Select a Number 1-9 To Select Your Move. (Top Left = 1 and Bottom Right = 9)" << endl;
				cout << line1 << endl << line2 << endl << line3 << endl;
				cin >> moveInput;
			}
			checkValidMove(moveInput);
			moves[moveCount] = moveInput;
			moveCount++;
			makeMovePlayer1(moveInput);
			if (checkWinPlayer1())
			{
				system("CLS");
				cout << line1 << endl << line2 << endl << line3 << endl;
				cout << "Player 1 Wins!" << endl;
				system("pause");
				return 0;
			}
			cout << endl;
		}
		cout << "Player 2 (O), Select a Number 1-9 To Select Your Move. (Please read from left to right where top left = 1 and bottom right = 9)" << endl;
		cout << line1 << endl << line2 << endl << line3 << endl;
		cin >> moveInput;
		while (!cin >> (int)moveInput) 
			{
				cout << "INVALID INPUT." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Player 2 (O), Select a Number 1-9 To Select Your Move. (Top Left = 1 and Bottom Right = 9)" << endl;
				cout << line1 << endl << line2 << endl << line3 << endl;
				cin >> moveInput;
			}
		checkValidMove(moveInput);
		moves[moveCount] = moveInput;
		moveCount++;
		makeMovePlayer2(moveInput);
		if (checkWinPlayer2())
		{
			system("CLS");
			cout << line1 << endl << line2 << endl << line3 << endl;
			cout << "Player 2 Wins!" << endl;
			system("pause");
			return 0;
		}
		system("CLS");
		cout << line1 << endl << line2 << endl << line3 << endl;
		cout << "The Game Ends in a Draw!" << endl;
	}
	//Allows the Players to see the endgame board before closing the command prompt.
	system("pause");
	return 0;
}
