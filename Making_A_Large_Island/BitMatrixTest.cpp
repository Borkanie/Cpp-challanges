#include <iostream>
#include <vector>
#include "BitMatrix.cpp"

#include <vector>
#include <array>

using namespace std;
#ifdef TEST
#include <gtest/gtest.h>
// BUILD
//  C:\msys64\mingw64\bin\g++.exe -fdiagnostics-color=always C:\Cpp-Learning\Cpp-challanges\Valid_Number\main.cpp -lgtest -lgtest_main -g -o C:\Cpp-Learning\Cpp-challanges\Valid_Number\main.exe

/* Test Creation of number fromn string
 *****************************************************************************/
TEST(ComplexNumberTest, Multiplication)
{
    // Arrange
    std::string expected = "0 0 \n0 0\n";

    // Act
    BitWise::Matrix matrix(2, 2);

    // Assert
    EXPECT_EQ(matrix.ToString(), expected);
}
#endif
int main(int argc, char **argv)
{
#ifdef TEST
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
#endif
    // Arrange
    std::string expected = "0 0 \n0 0\n";

    // Act
    BitWise::Matrix matrix(2, 2);
    cout << matrix;
    

    return 0;
}