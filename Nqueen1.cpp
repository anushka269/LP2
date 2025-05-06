#include<iostream>
#include<ctime>
#include<vector>
using namespace std;
class NQueen_Backtracking{
private:
    int size;
    int count;
    vector<vector<bool>> board;  
public:
    NQueen_Backtracking(){
        cout<<"Enter the Size of Chessboard:";
        cin>>size;
        board=vector<vector<bool>>(size,vector<bool>(size,false));
        count=0;
    }
    //print PrintBoard
void PrintBoard(){
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col]) 
                cout << "Q ";
            else 
                cout << "X ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(int row,int col){
    //check for columns
    for (int i = 0; i < size; i++) {
        if (board[i][col]) return false;
    }

    // Check backward slash (\) diagonal
    int i = row, j = col;
    while (i >= 0 && j >= 0) {
        if (board[i][j]) return false;
        i--; j--;
    }

    // Check forward slash (/) diagonal
    i = row, j = col;
    while (i >= 0 && j < size) {
        if (board[i][j]) return false;
        i--; j++;
    }

    return true;
}
//solve backtraking
void solve(int row){
    if(row==size){
        count++;
        PrintBoard();
        return;
    }
  for(int col=0;col<size;col++){
    if(isSafe(row,col)){
        board[row][col]=true;
        solve(row+1);
        board[row][col]=false;//backtracking
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
int main(){
    NQueen_Backtracking solver;
    solver.startSolving();
    return 0;
}