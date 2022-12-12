#include <iostream>
#include <string>

namespace Complex
{
    class Number
    {
    private:
    public:
        int Real = 0;
        int Imaginary = 0;
        Number()
        {
        }

        Number(double real, double imag)
        {
            this->Real = real;
            this->Imaginary = imag;
        }

        Number(std::string number) : Number()
        {
            const char *character = number.c_str();
            int imagSign = 0;
            int realSign = 0;
            bool imaginaryPart = false;
            int i = 0;
            if (*character == '-')
            {
                i = 1;
                realSign = -1;
            }
            else
            {
                realSign = 1;
            }
            for (; i < number.length(); i++)
            {
                if ('0' <= *(character + i) && *(character + i) <= '9')
                {
                    if (imaginaryPart)
                    {
                        Imaginary = Imaginary * 10 + imagSign * (*(character + i) - '0');
                    }
                    else
                    {
                        Real = Real * 10 + realSign * (*(character + i) - '0');
                    }
                }
                else
                {
                    if(*(character+i)=='i')
                        break;
                    if (*(character + i) == '-' || (*(character + i) == '+' && *(character + i+1) == '-'))
                    {
                        imagSign = -1;
                    }
                    else
                    {
                        imagSign = 1;
                    }
                    imaginaryPart = true;
                }
            }
        }

        // copy assignment
        Number &operator=(const Number &other)
        {
            // Guard self assignment
            if (this == &other)
                return *this;

            this->Imaginary = other.Imaginary;
            this->Real = other.Real;
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const Number &obj)
        {
            os << obj.Real << " " << obj.Imaginary << "i\n";
            // write obj to stream
            return os;
        }

        Number operator+(const Number &number) const
        {
            Number res;
            res.Real = this->Real + number.Real;
            res.Imaginary = this->Imaginary + number.Imaginary;
            return res;
        }

        Number operator-(const Number &number) const
        {
            Number res;
            res.Real = this->Real - number.Real;
            res.Imaginary = this->Imaginary - number.Imaginary;
            return res;
        }

        Number operator*(const Number &number) const
        {
            return Number(this->Real * number.Real - this->Imaginary * number.Imaginary,
                            this->Real * number.Imaginary + this->Imaginary * number.Real);
        }

        std::string ToString() const
        {
            std::string res;
            res += std::to_string(this->Real);
            res += "+";
            res += std::to_string(this->Imaginary);
            res += "i";
            return res;
        }
    };
    class Solution
    {
    public:
        std::string complexNumberMultiply(std::string num1, std::string num2)
        {
            Number n1(num1);
            Number n2(num2);
            Number result=(n1 * n2);
            return result.ToString();
        }
    };
}