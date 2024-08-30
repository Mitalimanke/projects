#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    cout << endl;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << ' ' << cell << ' ';
            if (&cell != &row.back()) cout << '|';
        }
        cout << endl;
        if (&row != &board.back()) cout << "---|---|---" << endl;
    }
    cout << endl;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void getMove(vector<vector<char>>& board, char player) {
    int move;
    while (true) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        if (move < 1 || move > 9) {
            cout << "Invalid move. Please enter a number between 1 and 9." << endl;
            continue;
        }
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] != ' ') {
            cout << "Cell already taken. Choose another one." << endl;
            continue;
        }
        board[row][col] = player;
        break;
    }
}

void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);
        getMove(board, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            return;
        }

        if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            return;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}