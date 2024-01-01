#include <iostream>
#include <vector>
using namespace std;

void displayBoard(const vector<vector<char> > &board) {
    cout << "-------------" << endl;
    for (const auto &row : board) {
        cout << "| ";
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin(const vector<vector<char> > &board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char> > &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameEnd = false;

    do {
        displayBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameEnd = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameEnd = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; 
        }

    } while (!gameEnd);

    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        main(); 
    } else {
        cout << "Thank you for playing Tic-Tac-Toe!" << endl;
    }

    return 0;
}
