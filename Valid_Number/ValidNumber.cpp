#include <iostream>
#include <string>

namespace ValidNumber
{
    class Solution
    {
    public:
        bool isNumber(std::string s)
        {
            const char *caracter = s.c_str();
            bool foundE = false;
            if (*caracter == '-' || *caracter == '+' || ('0' <= *caracter && *caracter <= '9'))
            {
                for (int i = 1; i < s.length(); i++)
                {
                    if (*(caracter + i) > '9' || *(caracter + i) < '0')
                    {
                        if (!foundE)
                        {
                            if ((*(caracter + i) == 'e' || *(caracter + i) == 'E'))
                            {
                                if(i == s.length()-1)
                                    return false;
                                foundE = true;
                                continue;
                            }
                            if (*(caracter + i) == '.')
                            {
                                continue;
                            }
                        }
                        else
                        {
                            if(*(caracter+i) == '-' || *(caracter+i) == '+'){
                                if(*(caracter+i-1)=='e' || *(caracter+i-1) == 'E'){
                                    continue;
                                }
                                //std::cout << "Sign only after \'e\' or \'E\' not "<< (char)*(caracter+i-1) << std::endl;
                                return false;
                            }
                        }
                        //std::cout << "Tis guy is wrong "<< (char)(*(caracter+i)) << std::endl;
                        //std::cout << "This index is wrong "<< i << std::endl;
                        return false;
                    }
                }
                return true;
            }
            else
            {
                //std::cout << "Character " << (*caracter) << " is NOT number nor \'+\' or \'-\'" << std::endl;
                return false;
            }
        }
    };
}