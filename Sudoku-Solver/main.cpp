#include <iostream>
#include <vector>

using namespace std;

int size=9;

class Solution {
public:
    static void printSolution(const vector<vector<char>> board){
        for(int i=0;i<board.size();i++){
            cout<<"[ ";
            for(int j=0;j<board[i].size();j++){
                cout<<board[i][j]<<" ";                
            }
            cout<<"]"<<endl;
        }
        cout<<endl;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
    }

    vector<vector<char>> solveSudokuStep(vector<vector<char>> board,int line,int column){
        for(int i=1;i<=9;i++){
            bool isGood=true;
            //check line
            for(int l=0;l<board.size();l++){
                if(board[l][column]==i){
                    isGood=false;
                    break;
                }
            }
            if(!isGood) continue;
            for(int c=0;c<board.size();c++){
                if(board[line][c]==i){
                    isGood=false;
                    break;
                }
            }
            if(!isGood) continue;
            //check square
        }
    }
};

void applySolution(vector<vector<char>>& board){
    // Line 1
    board[0][0]='5';
    board[0][1]='3';
    board[0][4]='7';
    //Line 2
    board[1][0]='6';
    board[1][3]='1';
    board[1][4]='9';
    board[1][5]='5';
    //Line 3
    board[2][1]='5';
    board[2][2]='5';
    board[2][7]='5';
    //Line 4
    board[3][0]='8';
    board[3][4]='6';
    board[3][7]='3';
    //Line 5
    board[4][0]='4';
    board[4][3]='8';
    board[4][5]='3';
    board[4][7]='1';
    //Line 6
    board[5][0]='7';
    board[5][4]='2';
    board[5][7]='6';
    //Line 7
    board[6][2]='6';
    board[6][5]='2';
    board[6][6]='8';
    //Line 8   
    board[7][3]='4';
    board[7][4]='1';
    board[7][5]='9';
    board[7][7]='5';
    //Line 9
    board[8][8]='8';
    board[8][7]='7';
    board[8][9]='9';
}

int main(char* args){
    vector<vector<char>> matrix(9, vector<char>(9,'.'));
    Solution::printSolution(matrix);
    Solution solution;
    applySolution(matrix);
    Solution::printSolution(matrix);
    cin.get();
    return 0;
}