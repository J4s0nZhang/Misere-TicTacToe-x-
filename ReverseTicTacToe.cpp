/*
Chapter 6.4.4
Jason Zhang
Nov 20 2017
Submitted to Dr. Noukhovitch
ICS4U1-01

X only misere tic tac toe
Both player play "X": this gets rid of ties that make the game mundane
First to 3 in a row LOSES: this creates more strategy as now you are trying to
force the other player to make 3 in a row.
*/
#include <iostream>
using namespace std;

class board{ //the superclass will be called board
public:
	char grid[10];
    board(){ //constructor fills the grid with numbers from 1-9 start from index 1
    	for(int i = 0; i < 10; i++){
    		grid[i] = '0' +i;
    	}
    }
    //because there are more functions it will be more clear to define them outside
    void DrawBoard(char grid[]);
    bool GetMove(int move, char grid[]);
    int checkwin(char grid[]);
    void reset(char grid[]);
};


void board::DrawBoard(char grid[])
/*
 * pseudo-code:
 * function for outputting the current state of the board
 * a series of formatted cout statments
 */
{
	cout << "___________________________" << endl;
    cout << endl << "     |     |     " << endl;
    cout << "  " << grid[1] << "  |  " << grid[2] << "  |  " << grid[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << grid[4] << "  |  " << grid[5] << "  |  " << grid[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << grid[7] << "  |  " << grid[8] << "  |  " << grid[9] << endl;

    cout << "     |     |     " << endl << endl;
}
bool board::GetMove(int move, char grid[])
/*
 * pseudo-code:
 * a function that changes the board based on player input
 * outputs a bool true or false, this determines if the game continues
 * otherwise depending on the input, change the corresponding grid element to 'X'
 * if the input is 11, output the instructions again
 * includes error checking
 */
{
	bool play = true;
	if(move == 0){
		play = false;
	}
	else if(move == 1 && grid[1] == '1'){
    	grid[1] = 'X';
    }
    else if(move == 2 && grid[2] == '2'){
    	grid[2] = 'X';
    }
    else if(move == 3 && grid[3] == '3'){
    	grid[3] = 'X';
    }
    else if(move == 4 && grid[4] == '4'){
    	grid[4] = 'X';
    }
    else if(move == 5 && grid[5] == '5'){
    	grid[5] = 'X';
            }
    else if(move == 6 && grid[6] == '6'){
    	grid[6] = 'X';
            }
    else if(move == 7 && grid[7] == '7'){
    	grid[7] = 'X';
            }
    else if(move == 8 && grid[8] == '8'){
    	grid[8] = 'X';
            }
    else if(move == 9 && grid[9] == '9'){
    	grid[9] = 'X';
            }
    else if(move == 11){

    	cout << endl << "Here are the instructions: " << endl;
		cout << "Input 0 to quit." << endl;
		cout << "Input numbers from 1-9 corresponding to the grid values." << endl;
		cout << "Input 10 to reset the board" << endl;
    }
    else{
    	cout << "Please input a valid input" << endl;

    }
	return play;

}

int board::checkwin(char grid[]){
	/*
	 * pseudo-code:
	 * check for 3 consecutive Xs in every row and every diagonal
	 * return 1 if its 3 in a row or -1 otherwise.
	 */
	if (grid[1] == grid[2] && grid[2] == grid[3])
		return 1;
	else if (grid[4] == grid[5] && grid[5] == grid[6])

		return 1;
	else if (grid[7] == grid[8] && grid[8] == grid[9])

		return 1;
	else if (grid[1] == grid[4] && grid[4] == grid[7])

		return 1;
	else if (grid[2] == grid[5] && grid[5] == grid[8])

		return 1;
	else if (grid[3] == grid[6] && grid[6] == grid[9])

		return 1;
	else if (grid[1] == grid[5] && grid[5] == grid[9])

		return 1;
	else if (grid[3] == grid[5] && grid[5] == grid[7])

		return 1;
	else
		return -1;
}

void board::reset(char grid[]){
	/*
	 * pseudo-code:
	 * fill the grid elements with numbers again
	 * "resets" the board state
	 */
	for(int i = 0; i < 10; i++){
	    		grid[i] = '0' +i;
	    	}

}
//The tripleboard subclass only needs one new method, it uses the methods of its superclass to
//do most of the work

class tripleBoard:public board{
/*
 * This sub class is for the real game mode of X only misere tic tac toe.
 * The game uses three boards, everytime 3 consecutive Xs are found on a board,
 * said board is considered "dead". The players can play on any board they want,
 * as long as it is not dead. The victor is decided a player kills the last board and
 * loses. This game mode requires way more strategy as killing boards may be a good thing
 * as long it sets up the win on the last board. The single board tictactoe has a
 * major flaw in that if both players play perfectly, the first player will always win.
 */


public:
	char grid1[10],grid2[10],grid3[10]; //3 arrays this time
	tripleBoard(){ //initialise all 3 arrays with numbers

		for(int i = 0; i < 10; i++){
		    grid1[i] = '0' +i;
		}
		for(int i = 0; i < 10; i++){
		    grid2[i] = '0' +i;
		}
		for(int i = 0; i < 10; i++){
		     grid3[i] = '0' +i;
		}
	}
	void DrawBoards(bool one, bool two , bool three){
		/*
		 * uses the drawboard method from the superclass, but now includes feature for the
		 * 3 board tictactoe format
		 * pseudo-code:
		 * check if each board is dead, if not, output the board, if the board is dead
		 * output board [] is dead
		 */

		if(one){ //if board one isnt dead
			cout << "Board 1 active" << endl;
			DrawBoard(grid1);
		}
		else{
			cout << "Board 1 dead" << endl;
		}
		if(two){ //if board two isnt dead
			cout << "Board 2 active" << endl;
			DrawBoard(grid2);
		}
		else{
			cout << "Board 2 dead" << endl;
		}
		if(three){ //if board three isnt dead
			cout << "Board 3 active" << endl;
			DrawBoard(grid3);
		}
		else{
			cout << "Board 3 dead" << endl;
		}
	}

};
int main()
{

	/*
	 * pseudo-code:
	 * initialise variables and output instructions
	 * the first while loop is for the very start of the game
	 * when the player selects their game mode or quits
	 *
	 * the second while loop is the real game
	 * get the user input and manipulate the game based on them
	 *
	 */
    bool play = true, one = true, two = true, three = true; //play keeps the while loop running, one, two and three are for the 3 board mode
    int player = 1; //for switching players
    int result, input, gametype; //variables for the result of the game, the user input and the game type

    cout << "Welcome to X only misere TicTacToe" << endl;
    cout << "Here are the instructions once the game begins: " << endl;
    cout << "Input 0 to quit." << endl;
    cout << "Input numbers from 1-9 corresponding to the grid values." << endl;
    cout << "Input 11 to see instructions again" << endl;
    cout << endl << "Input 1 for one board mode and 3 for three board mode: " << endl;

    board game; //Initialise variables for both game modes
    tripleBoard game2;

    while(true){
    	cin >> input; // get user input
		if(input == 1){
			gametype = 1;
			break;
		}
		else if(input == 3){
			gametype = 3;
			break;
		}
		else if(input == 0){
			cout << "Goodbye" << endl;
			return 0;
		}
		else{
			cout << "Please a valid number" << endl;
		}
    }
    while(play)
    {
    	if(gametype == 1){
    		cout << "X only Misere TicTacToe" << endl;
			game.DrawBoard(game.grid);
			cout <<"Player "<< player<<" Enter the field number you want play to: " << endl;
			cin >> input;

			play = game.GetMove(input, game.grid);

			result = game.checkwin(game.grid);

			if(result == 1){ //if there is 3 consecutive Xs
				game.DrawBoard(game.grid);
				cout << "Player "<<player<<" loses!" << endl;
				cout << endl << "Input 1 to reset the board or 2 to quit or 3 to switch game modes: " << endl;
				cin >> input;
				if(input == 2){
					play = false;
				}
				else if(input == 1){
					game.reset(game.grid);
					player = 2; //set player to 2 so it will always start the new game with player 1
				}
				else if(input == 3){
					gametype = 3; //switch game types
				}
				else{ //error trapping
					cout << "Please input a valid number" << endl;
				}
			}
			//switches players every loop
			if(player == 1){
				player = 2;
			}
			else{
				player = 1;
			}

		}
    	else{

    		int boardnum;
    		cout << "Three board X only Misere TicTacToe" << endl;
    		game2.DrawBoards(one,two,three);
    		cout <<"Player "<< player<<" Enter the board you want to play to:  " << endl;
    		cin >> boardnum;
    		if(boardnum == 0){
    			cout << "Goodbye.";
    			return 0;
    		}
    		cout <<"Player "<< player<<" Enter the field number you want play to: " << endl;
    		cin >> input;

    		if(boardnum == 1 && one){ //if input is 1 and board isnt dead
    			play = game2.GetMove(input, game2.grid1);
    			result = game2.checkwin(game2.grid1);
    			if(result == 1){ //if theres 3 consecutive Xs, kill the board
    				one = false;
				}
    		}
    		else if(boardnum == 2 && two){ //if input is 2 and board isnt dead
    			play = game2.GetMove(input, game2.grid2);
    			result = game2.checkwin(game2.grid2);

				if(result == 1){ //if theres 3 consecutive Xs, kill the board
					two = false;

				}

    		}
    		else if(boardnum == 3 && three){ //if input is 3 and board isnt dead
    			play = game2.GetMove(input, game2.grid3);
    			result = game2.checkwin(game2.grid3);
    			if(result == 1){ //if theres 3 consecutive Xs, kill the board
					three = false;
				}

    		}
    		else{
    			cout << "Please input a valid number" << endl;
    		}
    		if(one == false && two == false && three == false ){ //when all three boards are dead
    			cout << "Player "<<player<<" loses!" << endl;
    			cout << endl << "Input 1 to reset the board or 2 to quit or 3 to switch game modes: " << endl;
				cin >> input;
				if(input == 2){ //ends the game
					play = false;
				}
				else if(input == 1){ //resets everything
					one = true;
					two = true;
					three = true;
					game2.reset(game2.grid1);
					game2.reset(game2.grid2);
					game2.reset(game2.grid3);
					player = 2;
				}
				else if(input == 3){
					gametype = 1;
				}
				else{
					cout << "Please input a valid number" << endl;
				}
    		}
    		if(player == 1){
				player = 2;
			}
			else{
				player = 1;
			}

    	}

}
    cout << "Goodbye.";
    return 0;
}
