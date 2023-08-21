#include <iostream>
#include <vector>
using namespace std;

void addSol(vector<vector<string>>& ans, vector<vector<string>>& board, int n) {
    vector<string> temp;
    for (int i = 0; i < n; i++) {
        string row;
        for (int j = 0; j < n; j++) {
            row += board[i][j];
        }
        temp.push_back(row);
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<string>>& board, int n) {
    int x = row;
    int y = col;

    // Check for the same row
    while (y >= 0) {
        if (board[x][y].compare("Q") == 0) {
            return false;
        }
        y--;
    }

    // Check for diagonals
    x = row;
    y = col;

    while (x >= 0 && y >= 0) {
        if (board[x][y].compare("Q") == 0) {
            return false;
        }
        y--;
        x--;
    }

    x = row;
    y = col;

    while (x < n && y >= 0) {
        if (board[x][y].compare("Q") == 0) {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col, vector<vector<string>>& ans, vector<vector<string>>& board, int n) {
    if (col == n) {
        addSol(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = "Q";
            solve(col + 1, ans, board, n);
            board[row][col] = ".";
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> board(n, vector<string>(n, "."));
    vector<vector<string>> ans;
    solve(0, ans, board, n);
    return ans;
}

int main() {
    int n = 5; // for 5 x 5
    int board= 1;
    vector<vector<string>> solutions = solveNQueens(n);
    for (const auto& solution : solutions) {
        cout<<"Board "<<board++<<endl;
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << "-------------" << endl;
    }
    return 0;
}
