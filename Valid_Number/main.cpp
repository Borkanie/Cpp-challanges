#include <iostream>
#include <vector>
#include "ValidNumber.cpp"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

// BUILD
//  C:\msys64\mingw64\bin\g++.exe -fdiagnostics-color=always C:\Cpp-Learning\Cpp-challanges\Valid_Number\main.cpp -lgtest -lgtest_main -g -o C:\Cpp-Learning\Cpp-challanges\Valid_Number\main.exe

/* Test the `isNumber` method for CORRECT inputs
 *****************************************************************************/
TEST(ValidNumberTest, CorrectSymbols)
{

    // Arrange
    ValidNumber::Solution solution;
    std::vector<std::string> inputs = {".1","2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};

    for (int i = 0; i < inputs.size(); i++)
    {
        // Act
        bool result = solution.isNumber(inputs[i]);

        //Assert
        EXPECT_TRUE(result);
    }

    // Assert
    // Fails
    // ASSERT_EQ(value.c_str(),"Daddy");
    // works
    // ASSERT_STREQ(value.c_str(),"Daddy");
}

/* Test the `isNumber` method for INCORRECT inputs
 *****************************************************************************/
TEST(ValidNumberTest, InCorrectSymbols)
{

    // Arrange
    ValidNumber::Solution solution;
    std::vector<std::string> inputs = {"+E3","+.","","e-",".+",".e1","..",".",".e""abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"};

    for (int i = 0; i < inputs.size(); i++)
    {
        // Act
        bool result = solution.isNumber(inputs[i]);

        if(result){
            std::cout << inputs[i] <<std::endl;
        }

        //Assert
        EXPECT_FALSE(result);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}