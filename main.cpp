// Jordan Steer-Furderer
// CIS 25
// CONNECT FOUR!!

#include <iostream>
using namespace std;


//void player1 (int stuff[r][c]){
//for (int r = 0; r < 6; r++){
//    for (int c = 0; c < 7; c++){
//    cout << stuff[r][c] << " ";
//
//        }
//    }
//}

//int player1Prompt (int stuff){
//
//cin >> stuff;
//if(stuff > 6 ){
//cout << "try again" << endl;
//cin >> stuff;}
//
//}
//
//int player2Prompt (int stuff){
//cout << "Player 1 pick column 0 - 6" << endl;
//cin >> stuff;
//if(stuff > 6 ){
//cout << "try again" << endl;
//cin >> stuff;}
//
//}
//
//bool placePiece (char board[][7], int columnChoice, char playerPiece){
//    bool placed = false;
//    for(int i = 0; i < 7; i++){
//        if (board[i][columnChoice] == '-'){
//            board[i][columnChoice] = playerPiece;
//            placed = true;
//            break;
//        }
//    }
//    return placed;
//}

//bool checkForWin (char board[][7]){
//
//     for (int r = 0; r < 6; r++){
//        for (int c = 0; c < 7; c++){
//
//        }
//
//
//}



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


       if (lookDown(board, currentRow, currentColumn) == matchingPiece) {

        //cout << "found 1 to right" << endl;
        matchCountDown ++;
        if (lookUp(board, currentRow, currentColumn + 1) == matchingPiece) {

           // cout << "found 2 to right" << endl;
            matchCountDown ++;
            if (lookDown(board, currentRow, currentColumn + 2) == matchingPiece) {

           //     cout << "found 3 to right" << endl;
                matchCountDown ++;
            }

        }

    }


      if (matchCountDown == 3){
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
//
//            // debug this crap
          //  cout << "winner is wtf" << endl;
          //  cout << winner << endl;
//
//            bool winner_res = winner == 'x';
//            cout << winner_res << endl;
//
//            bool WTF = 'x' == 'x';
//            cout << WTF << endl;
//
            if (winner == 'x' || winner == 'o') {
                  cout << "FINAL WINNER is " << winner << endl;

                result = winner;
                goto end_of_all_loops;
            }
//
//
//
        }
//
    }
//
    end_of_all_loops:

    return result;
}


int main(){

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

    // test that move right works

//    char look_right_result = lookRight(board, 0, 0);
//
//    cout << "LOOK RIGHT RES" << endl;
//    cout << look_right_result << endl;


    int currentPlayer = 1;
    char playerPiece = 'x';
    while(true)
    {

        //TODO deal with placePieces return statment


        int userInput = askColumn(currentPlayer, board);

        placePiece(board, userInput, playerPiece);

        printBoard(board);

        //chek for winner here
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

        //TODO boardFull function to end loop

        char result = checkWin(board);

        //cout << "- - - - - what is the result this time " << endl;
       // cout << result << endl;



        if(result == 'x' || result == 'o') {
            //cout << "YEAHHHHHHHHH " << endl;
            //cout << result << endl;
        }

    }
//


    return 0;
}









