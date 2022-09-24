#include <iostream>

long long factorial(int x)
{
    long long result = 1;
    for (int i = 2; i <= x; i++)
    {
        result = result * i;
    }
    return result;
}

int numberOfZeros(int x)
{
    long long result = factorial(x);
    int zeros = 0;
    while (result % 10 == 0)
    {
        ++zeros;
        result = result / 10;
    }
    return zeros;
}

int onlineSolution(int factorialnumber)
{
    int zero_count = 0;
    for (int five_factor = 5;
         five_factor <= factorialnumber;
         five_factor *= 5)
    {
        zero_count += factorialnumber / five_factor;
    }
    return zero_count;
}

int numberOfZerosFast(int x)
{
    int zeros = 0;
    // we go trough all the multiples of 5 smaller than our number and count the fives
    // we don't need to count the 2's because there are always more twos than fives in a factiorial
    for (int i = 1; i <= x / 5; i++)
    {
        if (i % 5 == 0)
        {
            zeros += i / 5 + 1; // plus one comes from the fact we already dived by 5;
        }
        else
        {
            zeros += 1;
        }
    }
    return zeros;
}

// IPOTEZA: numarul de 0 este egal cu numarul 5 care incap in tooti multiplii a lui 5 mai mici sau egal cu numarul nostru

int main()
{
    char wait;
    int target;
    std::cin >> target;
    int result1 = numberOfZerosFast(target);
    std::cout << "Number of zeros is: " << result1 << std::endl;
    int result2 = onlineSolution(target);
    std::cout << "Number of zeros is with fast: " << result1 << std::endl;
    std::cin >> wait;
    return 0;
}