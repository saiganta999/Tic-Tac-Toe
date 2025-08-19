#include <iostream>
using namespace std;

 
void displayBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}
bool checkWin(char board[3][3], char player) 
{
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; 
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; 
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; 
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; 
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false; 
        }
    }
    return true;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} }; 
    int row, col;
    char currentPlayer = 'X'; 

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X | Player 2: O" << endl;

    while (true) {
        
        displayBoard(board);

    
        cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
        cin >> row >> col;

        
        row--;
        col--;

       
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        
        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;

}  

