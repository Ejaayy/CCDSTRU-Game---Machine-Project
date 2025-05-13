#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/**
 * Function: displayMap
 * Parameters:
 *   - arr[][4]: 4x4 character array representing the game board
 * Returns:
 *   - void (does not return anything)
 * Description:
 *   - Clears the console and prints the current game board.
 *   - Replaces null characters ('\0') with spaces for display.
 *   - Prints a formatted 4x4 grid.
 */
void displayMap(char arr[][4]){
	
	system ("cls"); // use system("clear") for linux or mac
	int i,j;
	
	//replace null with space for UI purposes
	for(i=0;i<4;i++){
		for(j=0; j<4;j++){
			if(arr[i][j] == '\0'){
				arr[i][j] = ' ';
			}
		}
	}
	
    printf("\t       _____ _        _____          \n");
    printf("\t      |_   _(_) ___  |_   _|_ _  ___ \n");
    printf("\t        | | | |/ __|   | |/ _  |/ __|\n");
    printf("\t        | | | | (__    | | (_| | (__ \n");
    printf("\t       _|_| |_|\\___|   |_|\\__,_|\\___|\n");
    printf("\t      | __ )  ___   ___  _ __ ___ | |\n");
    printf("\t      |  _ \\ / _ \\ / _ \\| '_   _ \\| |\n");
    printf("\t      | |_) | (_) | (_) | | | | | |_|\n");
    printf("\t      |____/ \\___/ \\___/|_| |_| |_(_)\n\n");

	printf("\t\t        1   2   3   4\n");
    printf("\t\t      +---+---+---+---+\n");
    printf("\t\t    1 | %c | %c | %c | %c |\n", arr[0][0], arr[0][1], arr[0][2], arr[0][3]);
    printf("\t\t      +---+---+---+---+\n");
    printf("\t\t    2 | %c | %c | %c | %c |\n", arr[1][0], arr[1][1], arr[1][2], arr[1][3]);
    printf("\t\t      +---+---+---+---+\n");
    printf("\t\t    3 | %c | %c | %c | %c |\n", arr[2][0], arr[2][1], arr[2][2], arr[2][3]);
    printf("\t\t      +---+---+---+---+\n");
    printf("\t\t    4 | %c | %c | %c | %c |\n", arr[3][0], arr[3][1], arr[3][2], arr[3][3]);
    printf("\t\t      +---+---+---+---+\n");
	
	//turn the space into Null again
	for(i=0;i<4;i++){
		for(j=0; j<4;j++){
			if(arr[i][j] == ' '){
				arr[i][j] = '\0';
			}
		}
	}
}

/**
 * Function: checkFree
 * Parameters:
 *   - arr[][4]: 4x4 character array representing the game board
 * Returns:
 *   - int: 1 if there is at least one empty space, 0 if the board is full
 * Description:
 *   - Checks if there are any empty spaces ('\0') in the grid
 */
int checkFree(char arr[][4]){
	int i,j;
	int availableFlag = 0; //assume its full
	
	//check if the boxes arent null
	for(i=0;i<4;i++){
		for(j=0; j<4;j++){
			if(arr[i][j] == '\0'){
				availableFlag = 1;
			}
		}
	}
	
	return availableFlag;
}


/**
 * Function: checkWin
 * Parameters:
 *   - arr[][4]: 4x4 character array representing the game board
 * Returns:
 *   - int: 1 if player 'X' wins, 2 if player 'O' wins, 0 if no winner
 * Description:
 *   - Checks if any player has won by filling a row, column, or diagonals
 */
int checkWin(char arr[][4]) {
    int i, j, k;
    int winner = 0;
    char players[2] = {'X', 'O'};
    int noOutsideWinConditionFlag = 0;
	
	//{ {(1,1),(1,2),(1,3),(1,4)}, {(1,1),(2,2),(3,3),(4,4)}, {(1,4),(2,3),(3,2),(4,1)}, {(4,1),(4,2),(4,3),(4,4)} }

    // Loop for each player 
    for(i = 0; i < 2; i++) { 
    
        // Check first row
        if (arr[0][0] == players[i] && arr[0][1] == players[i] && arr[0][2] == players[i] && arr[0][3] == players[i]) {
            noOutsideWinConditionFlag = 1;

            // Check for invalid extra
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    // Skip the first row, check if there's any invalid symbol elsewhere
                    if (!(j == 0 && k >= 0 && k < 4)) {
                        if (arr[j][k] == players[i]) {
                            noOutsideWinConditionFlag = 0;
                        }
                    }
                }
            }
            
            if (noOutsideWinConditionFlag == 1) {
                winner = i + 1;
            }
        }

        // Check last row
        if (arr[3][0] == players[i] && arr[3][1] == players[i] && arr[3][2] == players[i] && arr[3][3] == players[i]) {
            noOutsideWinConditionFlag = 1;

            // Check for invalid extra
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    // Skip the last row, check if there's any invalid symbol elsewhere
                    if (!(j == 3 && k >= 0 && k < 4)) {
                        if (arr[j][k] == players[i]) {
                            noOutsideWinConditionFlag = 0;
                        }
                    }
                }
            }
            
            if (noOutsideWinConditionFlag == 1) {
                winner = i + 1; // Player
            }
        }

        // Check main diagonal
        if (arr[0][0] == players[i] && arr[1][1] == players[i] && arr[2][2] == players[i] && arr[3][3] == players[i]) {
            noOutsideWinConditionFlag = 1;

            // Check for invalid extra
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    // Skip the main diagonal, check if there's any invalid symbol elsewhere
                    if (!(j == k)) {
                        if (arr[j][k] == players[i]) {
                            noOutsideWinConditionFlag = 0;
                        }
                    }
                }
            }

            if (noOutsideWinConditionFlag == 1) {
                winner = i + 1; // Player 'X' or 'O' wins
            }
        }

        // Check opposite diagonal
        if (arr[0][3] == players[i] && arr[1][2] == players[i] && arr[2][1] == players[i] && arr[3][0] == players[i]) {
            noOutsideWinConditionFlag = 1;

            // Check for invalid extra
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    // Skip the opposite diagonal, check if there's any invalid symbol elsewhere
                    if (!(j + k == 3)) {
                        if (arr[j][k] == players[i]) {
                            noOutsideWinConditionFlag = 0;
                        }
                    }
                }
            }

            if (noOutsideWinConditionFlag == 1) {
                winner = i + 1; // Player 'X' or 'O' wins
            }
        }
    }

    return winner; // Return winner, 0 if no winner, 1 for 'X', 2 for 'O'
}

int main() {
    char arr[4][4] = {0};
    int winnerFlag = 0;
    int turn = 1, go = 0; // Tres starts initially
	
	
    do {
    	//starting the map
        displayMap(arr);
        int x, y;
        char trash;
		
		//checking for turns
        if (turn && !go) {//condition means Tres
            printf("\n\t\t\t   Tres (X)"); 
            
        } else if (turn && go) { //condition means Uno turn
            printf("\n\t\t\t   Uno (O)");
            
        } else { //condition means Dos turn
            printf("\n\t\t\t Dos (Remove)");
        }

		//validation of input
		do {
		    printf("\n\t\t  Enter row and column: ");
		    

		    scanf(" %d %d%c", &x, &y, &trash);
		
		    x--; 
		    y--;
		
		    if (x < 0 || x > 3 || y < 0 || y > 3) {
		        printf("\n\t\tInvalid position! Try again.\n");
		        printf("\t\tPress any key to continue...\n");
		        getch();
		    }
		} while (x < 0 || x > 3 || y < 0 || y > 3); // Repeat until valid input is entered

        	
        if (turn) { //checks if its either tres or uno
            if (arr[x][y] == '\0') {
                if (go) { //check if uno
                    arr[x][y] = 'O';
                } else { //check if tres
                    arr[x][y] = 'X';
                }
                go = !go; // Switch between Tres and Uno
                if (!go) turn = 0; // Move to Dos after Uno
                
            } else {
                printf("\t\tPosition occupied! Try again.\n");
                printf("\t\tPress any key to continue...\n");
                getch();
            }
             
        } else { //since turn is false, it automatically means Dos turn
            if (arr[x][y] != '\0') {
                arr[x][y] = '\0';
                turn = 1; // Back to Tres after Dos
            } else {
                printf("\t\tNo piece to remove! Try again.\n");
                printf("\t\tPress any key to continue...\n");
                getch();
            }
        }

        winnerFlag = checkWin(arr); //check if someone won after its turn
        
    } while (winnerFlag == 0 && checkFree(arr)); 
    //game will go on until there is no winner and there is still a free position
    //it will end if someone won or if no more free positions

    displayMap(arr);
	
	//Display the winner
    if (winnerFlag == 1) {
        printf("\n\t\t\tTres (X) Wins!\n");
    } else if (winnerFlag == 2) {
        printf("\n\t\t\tUno (O) Wins!\n");
    } else {
        printf("\n\t\t\tDos (Remove) Wins!.\n");
    }

    return 0;
}


