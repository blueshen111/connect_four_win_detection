// Jordan Steer-Furderer
// CIS 25
// CONNECT FOUR!!

#include <iostream>
using namespace std;

// this function changes the index on the board from a '-' to a 'x' or 'o' depending on
// the users input
bool placePiece (char board[][7], int input, char playerPiece){
    for(int i = 6; i >= 0 ; i--){
        if (board[i][input] == '-'){
            board[i][input] = playerPiece;
            // return true;
            break;
        }
    }
}

// this functino simply prints the board
void printBoard (char board[][7]){
    for (int r = 0; r < 6; r++){
        for (int c = 0; c < 7; c++){
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
    cout << "=============" << endl;
}

// this function asks the user to choose which column to place a piece into
// and decides if the value is acceptable
int askColumn (int playerNumber, char board[][7]) {

    bool userInputOk = false;
    int columnChoice = -1;
    while(!userInputOk) {

        cout << "Player " << playerNumber <<  " pick column 0 - 6" << endl;
        cin >> columnChoice;

        // check if we're even using a valid entry
        if (columnChoice >= 0 && columnChoice <= 6) {


            // check if we're tring to drop a piece on a full or empty position
            if( board[0][columnChoice] == '-') {

                // simply break out of the whie loop to cause columnChoice to return
                userInputOk = true;
                break;
            } else {

                cout << "try again position already full" << endl;
            }


        } else {
            cout << "try again out of range error" << endl;
        }

    } // end of while loop

    return columnChoice;
}



char lookHoriz(char board[][7], int currentRow, int currentColumn) {
    if (currentColumn == 6){
        return NULL;
    }
    return board[currentRow][currentColumn + 1];
}

char lookDiagDown (char board[][7], int currentRow, int currentColumn) {
    if (currentColumn == 6){
        return NULL;
    }
    return board[currentRow - 1][currentColumn + 1];
}

char lookDiagRight (char board[][7], int currentRow, int currentColumn) {
    if (currentColumn == 6){
        return NULL;
    }
    return board[currentRow + 1][currentColumn + 1];
}



char lookVert(char board[][7], int currentRow, int currentColumn) {
    if (currentRow == 0){
        return NULL;
    }
    return board[currentRow + 1][currentColumn];
}

// this function looks horizontally from the current position and decides if there are four
// like characters in a row either in a column or in a row
char checkWinFromCurrentPosition(char board[][7], int currentRow, int currentColumn){

    char matchingPiece = board[currentRow][currentColumn];
    if (matchingPiece == '-') {
        return false;
    }

    int matchCountHoriz = 0;
    int matchCountVert = 0;
    int matchCountDiagDown = 0;
    int matchCountDiagRight = 0;

        if (lookDiagRight(board, currentRow, currentColumn) == matchingPiece) {

        //cout << "found 1 to right" << endl;
        matchCountDiagRight ++;
        if (lookDiagRight(board, currentRow + 1, currentColumn + 1) == matchingPiece) {

           // cout << "found 2 to right" << endl;
            matchCountDiagRight ++;
            if (lookDiagRight(board, currentRow + 2, currentColumn + 2) == matchingPiece) {

           //     cout << "found 3 to right" << endl;
                matchCountDiagRight ++;
            }

        }

    }


      if (matchCountDiagRight == 3){
        return matchingPiece;
    }

        if (lookDiagDown(board, currentRow, currentColumn) == matchingPiece) {

        //cout << "found 1 to right" << endl;
        matchCountDiagDown ++;
        if (lookDiagDown(board, currentRow - 1, currentColumn + 1) == matchingPiece) {

           // cout << "found 2 to right" << endl;
            matchCountDiagDown ++;
            if (lookDiagDown(board, currentRow - 2, currentColumn + 2) == matchingPiece) {

           //     cout << "found 3 to right" << endl;
                matchCountDiagDown ++;
            }

        }

    }


      if (matchCountDiagDown == 3){
        return matchingPiece;
    }


        if (lookVert(board, currentRow, currentColumn) == matchingPiece) {

        //cout << "found 1 to right" << endl;
        matchCountVert ++;
        if (lookVert(board, currentRow + 1, currentColumn) == matchingPiece) {

           // cout << "found 2 to right" << endl;
            matchCountVert ++;
            if (lookVert(board, currentRow + 2, currentColumn) == matchingPiece) {

           //     cout << "found 3 to right" << endl;
                matchCountVert ++;
            }

        }

    }


      if (matchCountVert == 3){
        return matchingPiece;
    }
    // check right
    if (lookHoriz(board, currentRow, currentColumn) == matchingPiece) {

        //cout << "found 1 to right" << endl;
        matchCountHoriz ++;
        if (lookHoriz(board, currentRow, currentColumn + 1) == matchingPiece) {

           // cout << "found 2 to right" << endl;
            matchCountHoriz ++;
            if (lookHoriz(board, currentRow, currentColumn + 2) == matchingPiece) {

           //     cout << "found 3 to right" << endl;
                matchCountHoriz ++;
            }

        }

    } // end checkb right

    //cout << "CHecking win from position" << endl;

    if (matchCountHoriz == 3){
        return matchingPiece;
    }


}


char checkWin(char board[][7]) {

    char result = '-';
//
    for (int r = 0; r < 6; r++) {

        for (int c = 0; c < 7; c++) {

           //cout << "- - - Check win at each board position: " << board[r][c] << endl;
           char winner = checkWinFromCurrentPosition(board, r, c);



            if (winner == 'x' || winner == 'o') {
                  cout << "WINNER IS " << winner << endl;

                result = winner;
            }

        }

    }


    return result;

}


int main(){
game:
    int columnChoice;
    //0 <= columnChoice <= 6;
    char x;
    char o;
    cout << "Welcome to Connect Four" << endl;

    cout << "=============" << endl;

    char board[6][7] = {    {'-', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'},
                                                              };
    printBoard(board);

    int currentPlayer = 1;
    char playerPiece = 'x';
    while(true)
    {

        int userInput = askColumn(currentPlayer, board);

        placePiece(board, userInput, playerPiece);

        printBoard(board);

        if(currentPlayer == 1)
        {
            currentPlayer = 2;
            playerPiece = 'o';
        }
        else
        {
            currentPlayer = 1;
            playerPiece = 'x';
        }


        char result = checkWin(board);

        if(result == 'x' || result == 'o') {
            //cout << "YEAHHHHHHHHH " << endl;
           // cout << result << endl;
            goto stop;
        }
    }

    stop:

    char playAgain;
    cout << "Play Again y/n? " << endl;
    cin >> playAgain;

    if (playAgain == 'y'){
        goto game;
    }

    else

    return 0;

}









