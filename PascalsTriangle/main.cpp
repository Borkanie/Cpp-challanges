#include <iostream>
#include "Source/Position.cpp"
#include <vector>
using namespace std;
vector<Position::Position> CreateLine(vector<Position::Position> rowBefore)
{
    vector<Position::Position> result;
    auto current = Position::Position(rowBefore.size(), 0);
    current.Value = 1;
    result.push_back(current);
    for (int i = 1; i < rowBefore.size(); i++)
    {
        current = Position::Position(rowBefore.size(), 0);
        current.Value = rowBefore.at(i - 1).Value + rowBefore.at(i).Value;
        result.push_back(current);
    }
    current = Position::Position(rowBefore.size(), rowBefore.size());
    current.Value = 1;
    result.push_back(current);
    return result;
}

void PrintLine(vector<Position::Position> line)
{
    for (int i = 0; i < line.size(); i++)
    {
        cout << line[i].Value << " ";
    }
    cout << endl;
}

vector<Position::Position> CreateTriangle(int lines, bool showDialog = false)
{
    vector<Position::Position> currentLine;
    currentLine.push_back(Position::Position(0, 0));
    if (showDialog)
    {
        PrintLine(currentLine);
    }

    for (int i = 1; i <= lines; i++)
    {
        currentLine = CreateLine(currentLine);
        if (showDialog)
        {
            PrintLine(currentLine);
        }
    }
    return currentLine;
}

int GetValue(Position::Position position, bool showTriangle=false)
{
    if(position.Number  == 0 || position.Number == position.Line)
        return 1;
    if(position.Number  == 1 || position.Number == position.Line-1)
        return position.Line;
    vector<Position::Position> currentLine = CreateTriangle(position.Line,showTriangle);
    return currentLine[position.Number].Value;
}

int main()
{
    int line = 0;
    int position = 0;
    cout << "What line do you want?" << endl;
    cin >> line;
    cout << "What position do you want?" << endl;
    cin >> position;
    char showAllTriange;
    cout << "Would you like to see the whole triangle? Y/N" << endl;
    cin >> showAllTriange;
    Position::Position trianglePosition(line, position);
    cout<< endl << "The desired value is : " << GetValue(trianglePosition,showAllTriange=='Y' || showAllTriange=='y'?true : false);
    cin >> position;
    return 0;
}