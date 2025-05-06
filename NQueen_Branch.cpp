#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class NQueens_BranchAndBound {
private:
    int size;
    vector<vector<bool>> board;
    vector<bool> columns, diag1, diag2;
    int count;

public:
    NQueens_BranchAndBound() {
        cout << "Enter size of chessboard: ";
        cin >> size;
        board = vector<vector<bool>>(size, vector<bool>(size, false));
        columns = vector<bool>(size, false);
        diag1 = vector<bool>(2 * size - 1, false);
        diag2 = vector<bool>(2 * size - 1, false);
        count = 0;
    }

    void printBoard() {
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                cout << (board[row][col] ? "Q " : "X ");
            }
            cout << endl;
        }
        cout << endl;
    }

    void solve(int row) {
        if (row == size) {
            count++;
            printBoard();
            return;
        }

        for (int col = 0; col < size; col++) {
            int d1 = row + col;
            int d2 = row - col + size - 1;

            if (!columns[col] && !diag1[d1] && !diag2[d2]) {
                board[row][col] = true;
                columns[col] = diag1[d1] = diag2[d2] = true;

                solve(row + 1);

                board[row][col] = false;
                columns[col] = diag1[d1] = diag2[d2] = false;
            }
        }
    }

    void startSolving() {
        clock_t start = clock();
        solve(0);
        cout << "Total solutions: " << count << endl;
        cout << "Time taken: " << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds." << endl;
    }
};

int main() {
    NQueens_BranchAndBound solver;
    solver.startSolving();
    return 0;
}
// }
// Enter size of chessboard: 4
// X Q X X 
// X X X Q 
// Q X X X 
// X X Q X 

// Q X X X 
// X X Q X 
// X X X Q 
// X Q X X 

// Total solutions: 2
// Time taken: 0.000004 seconds.
