#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << endl;
    // Open stream to file;
    ifstream mainFile("main.cpp");

    char line[256];
    // Read to the file
    while (mainFile.getline(line, 256))
    {
        cout << line << endl;
    }

    mainFile.close();
    return 0;
}