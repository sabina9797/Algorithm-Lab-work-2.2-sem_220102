#include <bits/stdc++.h>
using namespace std;
void print_board(vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
            {
                cout << "Q";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}
bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }
    // left dia;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)  // Moves diagonally up-left
    {
        if (board[i][j])
            return false;
    }
    
    // upper right  dia
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)  // Moves diagonally up-right
{
    if (board[i][j])
        return false;
}

    return true;
}
bool solve(vector<vector<int>> &board, int row, int n)
{
    if (row >= n)
        return true;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;

            if (solve(board, row + 1, n))
                return true;
            // back
            board[row][col] = 0;
        }
    }
    return false; // No valid position found for this r
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
   
    if(solve(board,0,n))
    {
        print_board(board,n);
    }else{
        cout << "NO solution exists\n";
    }
}