// Challange source: https://leetcode.com/problems/subarray-product-less-than-k/
#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int value = 0;
    if( nums.size() == 0){
        return 0;
    }
    if( nums.at(0) < k){
        cout << nums.at(0) << " ";
    }
    for (int i = 1; i < nums.size(); i++)
    {
        vector<int> newVector(nums.begin() + i, nums.begin() + nums.size());
        int toAdd = numSubarrayProductLessThanK(newVector, k);
        if (value + toAdd < k)
        {
            cout << newVector.at(0) << "  ";
            value += toAdd;
        }
        else
        {
            cout << endl;            
        }
        return value;
    }
}

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    // int nums[] = {10,5,2,6};
    int k = 100;
    numSubarrayProductLessThanK(nums, k);
    return 0;
}