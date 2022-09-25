#include <iostream>
#include <vector>

using namespace std;

int GreatestSum(int inputArray[],int size)
{
    int maximum = -1;
    int currentResult = 0;
    for (int i = 0; i < size; i++)
    {
        if (inputArray[i] < 0)
        {            
            if (currentResult > maximum)
            {
                maximum = currentResult;
            }
            currentResult = 0;
        }
        else
        {
            currentResult += inputArray[i];
        }
    }
    return maximum;
}
int main()
{
    int inputArray[]{1, 2, -5, 4, -3, 2};
    cout << "maxim array value: " << GreatestSum(inputArray,sizeof(inputArray) / sizeof(int));
    char in;
    cin >> in;
    return 0;
}