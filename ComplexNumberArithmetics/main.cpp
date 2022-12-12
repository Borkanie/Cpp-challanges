#include <iostream>
#include <vector>
#include "ComplexNumber.cpp"
#include <gtest/gtest.h>
#include <vector>
#include <array>

using namespace std;

// BUILD
//  C:\msys64\mingw64\bin\g++.exe -fdiagnostics-color=always C:\Cpp-Learning\Cpp-challanges\Valid_Number\main.cpp -lgtest -lgtest_main -g -o C:\Cpp-Learning\Cpp-challanges\Valid_Number\main.exe

/* Test Creation of number fromn string
 *****************************************************************************/
TEST(ComplexNumberTest,Multiplication)
{

    // Arrange
    Complex::Solution solution;
    std::vector<std::array<std::string, 3>> inputs;
    inputs.push_back({"1+0i", "0+0i", "0+0i"});
    inputs.push_back({"1+0i", "0+1i", "0+1i"});
    inputs.push_back({"1+3i", "0+-1i", "3+-1i"});
    inputs.push_back({"0+5i", "0+5i", "-25+0i"});
    inputs.push_back({"0+1i", "0+-3i", "3+0i"});
    inputs.push_back({"0+3i", "1+0i", "0+3i"});

    for (int i = 0; i < inputs.size(); i++)
    {
        std::array<std::string, 3> array = inputs[i];
        // Act
        std::string result = solution.complexNumberMultiply(array[0], array[1]);

        // Assert
        EXPECT_EQ(result, array[2]);
    }
}

/* Test the `isNumber` method for CORRECT inputs
 *****************************************************************************/
TEST(ComplexNumberTest,Addition)
{

    // Arrange
    std::vector<std::array<std::string, 3>> inputs;
    inputs.push_back({"1+0i", "0+0i", "1+0i"});
    inputs.push_back({"1+0i", "1+0i", "2+0i"});
    inputs.push_back({"1+-0i", "0+1i", "1+1i"});
    inputs.push_back({"1+-1i", "0+0i", "1+-1i"});
    inputs.push_back({"1+0i", "0+-1i", "1+-1i"});

    for (int i = 0; i < inputs.size(); i++)
    {
        std::array<std::string, 3> array = inputs[i];
        // Act
        Complex::Number result=Complex::Number(array[0]) + Complex::Number(array[1]);

        // Assert
        EXPECT_EQ(result.ToString(), array[2]);
    }
}


/* Test the `isNumber` method for CORRECT inputs
 *****************************************************************************/
TEST(ComplexNumberTest,Subtraction)
{

    // Arrange
    std::vector<std::array<std::string, 3>> inputs;
    inputs.push_back({"1+0i", "0+0i", "1+0i"});
    inputs.push_back({"1+0i", "1+0i", "0+0i"});
    inputs.push_back({"1+-0i", "0+1i", "1+-1i"});
    inputs.push_back({"1+-1i", "0+0i", "1+-1i"});
    inputs.push_back({"1+0i", "0+-1i", "1+1i"});

    for (int i = 0; i < inputs.size(); i++)
    {
        std::array<std::string, 3> array = inputs[i];
        // Act
        Complex::Number result=Complex::Number(array[0]) - Complex::Number(array[1]);

        // Assert
        EXPECT_EQ(result.ToString(), array[2]);
    }
}

/* Tests constructor with string.
******************************************************************************/
TEST(ComplexNumberTest,CorrectContructor)
{
    // Arrange
    std::vector<std::string> inputs = {"0+0i", "5+0i", "-5+0i", "2+2i", "-1+-1i"};

    for (int i = 0; i < inputs.size(); i++)
    {
        // Act
        Complex::Number number(inputs[i]);

        // Assert
        EXPECT_EQ(number.ToString(), inputs[i]);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}