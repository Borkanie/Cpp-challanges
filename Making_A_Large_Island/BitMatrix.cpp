#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <cstdlib>

#ifndef udouble
#define udouble unsigned long long
#define udoubleMax (((udouble)(1) << 63))
#endif
namespace BitWise
{
    void Add1BitToTheLeftOfUDouble(udouble *number)
    {
        *number = *number >> 1;
        *number = udoubleMax | *number;
    }
    /*
  A class capable of a bit matrix using doulbes soo it can hold up to a widt of 8*8=64 bits
  */
    class Matrix
    {
    public:
        Matrix(int lines, int columns,bool random=true)
        {
            if (columns > sizeof(double) * 8)
            {
                throw std::invalid_argument(" we are maxed at the size of a double");
            }
            this->lines = lines;
            for (int i = 1; i < columns; i++)
            {
                Add1BitToTheLeftOfUDouble(&mask);
            }
            matrix = new udouble[lines];
            for (int i = 0; i < lines; i++)
            {
                if(!random){
                    matrix[i] = 0;
                }else{
                    matrix[i] = ((udouble)std::rand()) << 8*7;
                }
                
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const Matrix &obj)
        {
            for (int i = 0; i < obj.lines; i++)
            {
                for (udouble j = udoubleMax; j <= obj.mask; Add1BitToTheLeftOfUDouble(&j))
                {
                    if ((obj.matrix[i] & j) > 0)
                    {
                        os << "1 ";
                    }
                    else
                    {
                        os << "0 ";
                    }
                }
                os << std::endl;
            }
            return os;
        }

        std::string ToString()
        {
            std::string result = "";
            for (int i = 0; i < this->lines; i++)
            {
                for (udouble j = udoubleMax; j <= this->mask; Add1BitToTheLeftOfUDouble(&j))
                {
                    if ((this->matrix[i] & j) > 0)
                    {
                        result += "1 ";
                    }
                    else
                    {
                        result += "0 ";
                    }
                }
                result += "\n";
            }
            return result;
        }

        udouble *matrix;
        udouble GetMask() const
        {
            return mask;
        }
        int GetLines() const
        {
            return lines;
        }

    private:
        udouble mask = ((udouble)(1) << 63);
        int lines;
    };

}