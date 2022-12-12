// source problem https://leetcode.com/problems/sudoku-solver/
#include <iostream>
#include <vector>

using namespace std;

const int size = 9;
const int getSquare(const int line, const int column)
{
    return (line / 3) * 3 + column / 3;
}

void applySolution(vector<vector<char>> &board)
{
    // Line 1
    board[0][0] = '5';
    board[0][1] = '3';
    board[0][4] = '7';
    // Line 2
    board[1][0] = '6';
    board[1][3] = '1';
    board[1][4] = '9';
    board[1][5] = '5';
    // Line 3
    board[2][1] = '9';
    board[2][2] = '8';
    board[2][7] = '6';
    // Line 4
    board[3][0] = '8';
    board[3][4] = '6';
    board[3][8] = '3';
    // Line 5
    board[4][0] = '4';
    board[4][3] = '8';
    board[4][5] = '3';
    board[4][8] = '1';
    // Line 6
    board[5][0] = '7';
    board[5][4] = '2';
    board[5][8] = '6';
    // Line 7
    board[6][1] = '6';
    board[6][6] = '2';
    board[6][7] = '8';
    // Line 8
    board[7][3] = '4';
    board[7][4] = '1';
    board[7][5] = '9';
    board[7][8] = '5';
    // Line 9
    board[8][4] = '8';
    board[8][7] = '7';
    board[8][8] = '9';
}

class Solution
{
public:
    static void printSolution(const vector<vector<char>> board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            cout << "[ ";
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "]" << endl;
        }
        cout << endl;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        if (solveSudokuStep(board, 0, 0))
        {
            cout << "we found a solution"<<endl;
            printSolution(board);
        }
        else
        {
            cout << "no suitable solution was found";
        }
    }

    bool solveSudokuStep(vector<vector<char>> &board, const int line, const int column)
    {
        //cout << "Now solving for line: " << line << " column: " << column << endl;
        if (board[line][column] != '.')
        {
            if (column == 8)
            {
                if (line == 8)
                    return true;
                return solveSudokuStep(board, line + 1, 0);
            }
            else
            {
                return solveSudokuStep(board, line, column + 1);
            }
        }
        for (int possibleValue = 1; possibleValue <= 9; possibleValue++)
        {
            bool isGood = true;
            // check line
            char charPossibleValue = possibleValue + 48; // convert int to char
            for (int l = 0; l < board.size(); l++)
            {
                if (board[l][column] == charPossibleValue)
                {
                    isGood = false;
                    break;
                }
            }
            if (!isGood)
                continue;
            for (int c = 0; c < board.size(); c++)
            {
                if (board[line][c] == charPossibleValue)
                {
                    isGood = false;
                    break;
                }
            }
            if (!isGood)
                continue;
            // check square
            const int square = getSquare(line, column);
            for (int l = (square / 3) * 3; l < (square / 3) * 3 + 3; l++)
            {
                for (int c = (square % 3) * 3; c < (square % 3) * 3 + 3; c++)
                {
                    if (board[l][c] == charPossibleValue)
                    {
                        isGood = false;
                        break;
                    }
                }
            }
            if (isGood)
            {
                board[line][column] = charPossibleValue;
                if (column == 8)
                {
                    if (line == 8)
                        return true;
                    else
                    {
                        if (!solveSudokuStep(board, line + 1, 0))
                        {
                            board[line][column] = '.';
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
                else
                {
                    if (!solveSudokuStep(board, line, column + 1))
                    {
                        board[line][column] = '.';
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(int arg, char *args)
{
    vector<vector<char>> matrix(9, vector<char>(9, '.'));
    // Solution::printSolution(matrix);
    Solution solution;
    applySolution(matrix);
    cout<<"solving for:"<<endl;
    Solution::printSolution(matrix);
    solution.solveSudoku(matrix);
    cin.get();
    return 0;
}