#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxAreea = 0;
        int firstIndex=0;
        int secondIndex=height.size()-1;
        for (int i = 0; i < height.size(); i++)
        {
            if(firstIndex==secondIndex) return maxAreea;
            if(height[firstIndex]<height[secondIndex]){
                int areea=(secondIndex-firstIndex)*height[firstIndex];
                if(areea>maxAreea){
                    maxAreea = areea;
                }
                firstIndex++;
            }else{
                int areea=(secondIndex-firstIndex)*height[secondIndex];
                secondIndex--;
                if(areea>maxAreea){
                    maxAreea = areea;
                }
            }

        }
        return maxAreea;
    }
    int maxAreaTooSlow(vector<int> &height)
    {
        int maxAreea = -1;
        int maxI = -1, maxJ = -1;
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int areea = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
                if (areea > maxAreea)
                {
                    maxAreea = areea;
                    maxI = i;
                    maxJ = j;
                }
            }
        }
        cout << "Max i,j:[" << maxI << "," << maxJ << "]" << endl;
        return maxAreea;
    }
};

int main()
{
    Solution solution;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << " the array is: ";
    for (int i = 0; i < height.size(); i++)
    {
        cout << height[i] << ", ";
    }
    cout << endl
         << "The result is:" << solution.maxArea(height) << endl;
    return 0;
}