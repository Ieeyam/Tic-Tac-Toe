#include <iostream>
using namespace std;

const char playerX = 'X', playerO = 'O';
char currentPlayer = playerX, winner = ' ';
int r = -1, c = -1;

void board() {
    char board[3][3] {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    

    for (int i = 0; i < 9; i++) {

        system("cls");

        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if (winner != ' ') {
            break;
        }

        cout << "Current player is " << currentPlayer << endl;

            while (true) {
            cout << "Enter r and c from 0-2 for row and column: ";
            cin >> r >> c;

            if (r < 0 || r > 2 || c < 0 || c > 2) {
                cout << "Invalid Input, Please try again!" << endl;
                continue;
            } else if (board[r][c] != ' ') {
                cout << "Placement Used, Please try again." << endl;
                continue;
            } else {
                break;
            }

            cin.clear();
            cin.ignore(10000, '\n');
        }

        board[r][c] = currentPlayer;

        if (currentPlayer == playerX) {
            currentPlayer = playerO;
        } else {
            currentPlayer = playerX;
        }

        for (r = 0; r < 3; r++) {
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
                winner = board[r][0];
            }
        }

        for (c  = 0; c < 3; c++) {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
                winner = board[0][c];
            }
        }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        } else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }
    }
    
    if (winner != ' ') {
        cout << "Player " << winner << " is the winner!" << endl;
    } else {
        cout << "Tie!" << endl;
    }
}

int main() {

    board();
    return 0;
}