#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<char>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 9; i += 3) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i + j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check for a win
bool checkWin(const vector<char>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) return true; // Rows
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) return true; // Columns
    }
    if (board[0] == player && board[4] == player && board[8] == player) return true; // Diagonal (top-left to bottom-right)
    if (board[2] == player && board[4] == player && board[6] == player) return true; // Diagonal (top-right to bottom-left)
    return false;
}

// Function to check for a draw
bool checkDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') return false; // If there's an empty cell, it's not a draw
    }
    return true; // No empty cells, it's a draw
}

int main() {
    char playAgain;
    do {
        vector<char> board(9, ' '); // Initialize the board with empty spaces
        char currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;

        cout << "Welcome to Tic-Tac-Toe!\n";

        while (!gameWon && !gameDraw) {
            printBoard(board);

            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;
            move--; // Adjust to 0-8 indexing

            if (move < 0 || move > 8 || board[move] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue; // Go back to the beginning of the loop
            }

            board[move] = currentPlayer;

            gameWon = checkWin(board, currentPlayer);
            gameDraw = checkDraw(board);

            if (gameWon) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
            } else if (gameDraw) {
                printBoard(board);
                cout << "It's a draw!\n";
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
            }
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}