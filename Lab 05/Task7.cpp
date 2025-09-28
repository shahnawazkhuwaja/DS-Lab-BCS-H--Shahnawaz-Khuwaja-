#include "iostream"
using namespace std;

#define N 4
int board[N][N];
void printBoard(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col){
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

void solveNQueens(int row){
    if (row == N){
        printBoard();
        return;
    }

    for (int col = 0; col < N; col++){
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solveNQueens(row + 1);
            board[row][col] = 0;
        }
    }
}

int main(){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    solveNQueens(0);
}