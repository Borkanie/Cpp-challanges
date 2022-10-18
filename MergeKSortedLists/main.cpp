// Challange source: https://leetcode.com/problems/merge-k-sorted-lists/
/*
Example
Input:
     lists = [[1,4,5],[1,3,4],[2,6]]
Output:
     [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/
// done using pointers
#include <iostream>

using namespace std;

#if (DEBUG == 1)
#define LOG(x) cout << x;
#elif (DEBUG == 0)
#include <fstream>
ofstream myfile;
#define LOG(x)                                 \
    myfile.open("release.txt", ios_base::app); \
    myfile << x;                               \
    myfile.close();
#endif
int **allocateMatrix(int *numberOfElementsOnLines)
{
    const int lines = sizeof(numberOfElementsOnLines) / sizeof(int) + 1;
    int **matrix = (int **)malloc(sizeof(int *) * lines);
    for (int i = 0; i < lines; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * numberOfElementsOnLines[i]);
    }
    return matrix;
}

void freeMatrix(int **matrix, int lines)
{
    for (int i = 0; i < lines; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int **getInputMatrix(int *listOfElements, int *elementOnLines)
{
    int **matrix = allocateMatrix(elementOnLines);
    int index = 0;
    const int lines = sizeof(elementOnLines) / sizeof(int);
    for (int i = 0; i <= lines; i++)
    {
        for (int j = 0; j < elementOnLines[i]; j++)
        {
            matrix[i][j] = listOfElements[index++];
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int *elementsOnLines)
{
    for (int i = 0; i <= sizeof(elementsOnLines) / sizeof(int); i++)
    {
        LOG("[ ");
        for (int j = 0; j < elementsOnLines[i]; j++)
        {
            LOG(matrix[i][j]);
            LOG(" ");
        }
        LOG("]");
        LOG(endl);
    }
    LOG(endl);
}

int *orderedList(int **matrix, int *elementsOnLines)
{
    const int numberOfLines = sizeof(elementsOnLines) / sizeof(int) + 1;
    int currentIndex[numberOfLines] = {0};
    int totalNumberOfElements = 0, elementsCycled = 0;
    for (int i = 0; i < numberOfLines; i++)
    {
        totalNumberOfElements += elementsOnLines[i];
    }
    int *result = (int *)malloc(sizeof(int) * totalNumberOfElements);
    while (elementsCycled < totalNumberOfElements)
    {
        int nextMin = 10000, minIndex = 0;
        for (int i = 0; i < numberOfLines; ++i)
        {
            if (currentIndex[i] < elementsOnLines[i])
            {
                if (matrix[i][currentIndex[i]] < nextMin)
                {
                    minIndex = i;
                    nextMin = matrix[i][currentIndex[i]];
                }
            }
        }
        ++currentIndex[minIndex];
        result[elementsCycled] = nextMin;
        elementsCycled++;
    }
    return result;
}

int main()
{

#if (DEBUG == 0)
    LOG("Merge K Sorted Lists\n");
#endif
    int listOfElements[] = {1, 4, 5, 1, 3, 4, 2, 6};
    int matrixStructure[] = {3, 3, 2};
    int **matrix = getInputMatrix(listOfElements, matrixStructure);
    printMatrix(matrix, matrixStructure);
    int* result=orderedList(matrix, matrixStructure);
    freeMatrix(matrix, sizeof(matrixStructure) / sizeof(int));
    int index=0;
    LOG("[");
    for (int i = 0; i < sizeof(matrixStructure) / sizeof(int) ; i++)
    {
        for(int j=0;j<matrixStructure[i];j++){
            LOG(result[index++]);
            LOG(",");
        }
       
    }
    LOG("]");
#if (DEBUG == 1)
    cin.get();
#endif
    return 0;
}