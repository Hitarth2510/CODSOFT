#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void printBoard() {
    cout << "Current board:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--+---+--\n";
    }
}

bool checkWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void makeMove(char player) {
    int choice;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / SIZE;
    int col = (choice - 1) % SIZE;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move, try again.\n";
        makeMove(player);
    } else {
        board[row][col] = player;
    }
}

int main() {
    char player = 'X';
    bool gameWon = false;
    bool draw = false;

    while (!gameWon && !draw) {
        printBoard();
        makeMove(player);
        gameWon = checkWin(player);
        if (!gameWon) {
            draw = checkDraw();
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    printBoard();

    if (gameWon) {
        cout << "Player " << player << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}