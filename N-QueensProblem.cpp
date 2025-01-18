#include <bits/stdc++.h>
using namespace std;

#define N 8

bool isSafe(int board[N][N], int row, int col) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

bool solveNQueens(int board[N][N], int row) {
    if (row >= N) return true; // All queens placed successfully

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Place queen

            if (solveNQueens(board, row + 1)) return true; // Recur for next row

            board[row][col] = 0; // Backtrack
        }
    }
    return false; // No solution for this configuration
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    int board[N][N] = {0};
    if (solveNQueens(board, 0)) {
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }
    return 0;
}



/*
N = 4
. Q . .
. . . Q
Q . . .
. . Q .

N = 8
Q . . . . . . .
. . . . Q . . .
. . . . . . Q .
. . Q . . . . .
. . . . . Q . .
. Q . . . . . .
. . . Q . . . .
. . . . . . . Q
*/