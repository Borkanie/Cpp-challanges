// Challange source: https://leetcode.com/problems/subarray-product-less-than-k/
// Note I read it wrong i though it just had to be any combination of elements in array not necessarry a subarray

#include <iostream>
#include <vector>

using namespace std;
vector<int> current;
int prod=1;
void printVector(const vector<int> vector)
{
    cout << " [";
    for (int i : vector)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int iter = 0;
    while (nums.begin() + iter != nums.end() && k-prod*nums.at(iter) > 0)
    {
        prod*=nums.at(iter);
        current.push_back(nums.at(iter));
        cout<< "prod=" << prod;
        printVector(current);
        iter++;                
        vector<int> newVector(nums.begin() + iter, nums.end());
        numSubarrayProductLessThanK(newVector, k);
        current.pop_back();
        prod/=nums.at(iter-1);        
    }
    
    return 0;
}

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    // int nums[] = {10,5,2,6};
    int k = 100;
    numSubarrayProductLessThanK(nums, k);
    return 0;
}