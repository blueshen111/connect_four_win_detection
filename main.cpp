// Jordan Steer-Furderer
// CIS 25
// CONNECT FOUR!!

#include <iostream>
using namespace std;

bool placePiece (char board[][7], int input, char playerPiece){
    for(int i = 6; i >= 0 ; i--){
        if (board[i][input] == '-'){
            board[i][input] = playerPiece;
            // return true;
            break;
        }
    }
}


void printBoard (char board[][7]){
    for (int r = 0; r < 6; r++){
        for (int c = 0; c < 7; c++){
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
    cout << "=============" << endl;
}


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
                // not a dash, do wat?
                cout << "try again position already full" << endl;
            }


        } else {
            cout << "try again out of range error" << endl;
        }

    } // end of while loop

    return columnChoice;
}


char lookLeft(char board[][7], int currentRow, int currentColumn) {
    if (currentColumn == 0){
        return NULL;
    }
    return board[currentRow][currentColumn - 1];
}


char lookRight(char board[][7], int currentRow, int currentColumn) {
    if (currentColumn == 6){
        return NULL;
    }
    return board[currentRow][currentColumn + 1];
}


char lookUp(char board[][7], int currentRow, int currentColumn) {
    if (currentRow == 0){
        return NULL;
    }
    return board[currentRow + 1][currentColumn];
}


char lookDown(char board[][7], int currentRow, int currentColumn) {
    if (currentRow == 5){
        return NULL;
    }
    return board[currentRow - 1][currentColumn];
}


char checkWinFromCurrentPosition(char board[][7], int currentRow, int currentColumn){

    char matchingPiece = board[currentRow][currentColumn];
    if (matchingPiece == '-') {
        return false;
    }

    int matchCountRight = 0;
    int matchCountLeft = 0;
    int matchCountUp = 0;
    int matchCountDown = 0;



        if (lookUp(board, currentRow, currentColumn) == matchingPiece) {

        //cout << "found 1 to right" << endl;
        matchCountUp ++;
        if (lookUp(board, currentRow + 1, currentColumn) == matchingPiece) {

           // cout << "found 2 to right" << endl;
            matchCountUp ++;
            if (lookUp(board, currentRow + 2, currentColumn) == matchingPiece) {

           //     cout << "found 3 to right" << endl;
                matchCountUp ++;
            }

        }

    }


      if (matchCountUp == 3){
        return matchingPiece;
    }
    // check right
    if (lookRight(board, currentRow, currentColumn) == matchingPiece) {

        //cout << "found 1 to right" << endl;
        matchCountRight ++;
        if (lookRight(board, currentRow, currentColumn + 1) == matchingPiece) {

           // cout << "found 2 to right" << endl;
            matchCountRight ++;
            if (lookRight(board, currentRow, currentColumn + 2) == matchingPiece) {

           //     cout << "found 3 to right" << endl;
                matchCountRight ++;
            }

        }

    } // end checkb right

    //cout << "CHecking win from position" << endl;

    if (matchCountRight == 3){
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









