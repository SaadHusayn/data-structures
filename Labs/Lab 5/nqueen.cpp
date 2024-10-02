#include <iostream>
#include <cmath>
using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check if there's a queen in the same column or diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(int board[], int n, int row = 0) {
    if (row == n) {
        // All queens are placed successfully
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // Place the queen in this column
            // Recursively place queens in the next row
            if (solveNQueens(board, n, row + 1)) {
                return true; // If a solution is found, return true
            }
            // If placing the queen in this column doesn't lead to a solution, backtrack
            board[row] = -1;
        }
    }

    // If no safe position is found, return false (backtrack)
    return false;
}

// Function to print the board (position of queens)
void printSolution(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q "; // Queen is placed at (i, j)
            } else {
                cout << ". "; // Empty space
            }
        }
        cout << endl;
    }
}

int main() {
    int n = 50; // For example, solving 8-Queens
    int board[50]; // Array to hold the position of queens
    // Initialize the board to -1 (no queens placed)
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }

    if (solveNQueens(board, n)) {
        cout << "Solution found:\n";
        printSolution(board, n); // Print the solution
    } else {
        cout << "No solution exists.\n";
    }
    
    for(int i=0;i<n;i++){
        cout<<board[i]<<" ";
    }
    

    return 0;
}
