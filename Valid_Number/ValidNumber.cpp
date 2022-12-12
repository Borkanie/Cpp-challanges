#include <iostream>
#include <string>

namespace ValidNumber
{
    class Solution
    {
    private:
        bool isDot(const char c)
        {
            return c == '.';
        }
        bool isDigit(const char c)
        {
            return ('0' <= c && c <= '9');
        }
        bool isBigOrSmallE(const char c)
        {
            return c == 'e' || c == 'E';
        }
        bool isSign(const char c)
        {
            return c == '-' || c == '+';
        }
        bool StartsCorrectly(std::string s)
        {
            const char *character = s.c_str();
            return isSign(*character) || isDigit(*character) || isDot(*character);
        }

    public:
        bool isNumber(std::string s)
        {
            const char *character = s.c_str();
            char lastChar = *(s.c_str() + s.length() - 1);
            if (s.length() > 0 && StartsCorrectly(s) && (isDigit(lastChar) || isDot(lastChar)))
            {
                bool foundE = false;
                bool usedDot = false;
                if (isDot(*character))
                {
                    bool isFoloowedByDigit = isDigit(*(character + 1));
                    if (s.length() == 2)
                        return isFoloowedByDigit;
                    else if (!isFoloowedByDigit)
                        return false;
                    usedDot = true;
                }
                if (isSign(*character))
                {
                    if(!isDigit(*(character + 1))){
                        if(s.length()==2){
                            return false;
                        }
                        else{
                            if(!isDot(*(character+1))){
                                return false;
                            }
                        }
                    }
                }
                for (int i = 1; i < s.length(); i++)
                {
                    const char currentCharacter = *(character + i);
                    if (isDigit(currentCharacter))
                    {
                        continue;
                    }
                    else
                    {
                        if (foundE)
                        {
                            if (isSign(currentCharacter))
                            {
                                const char previousChar = *(character + i - 1);
                                if (isBigOrSmallE(previousChar))
                                {
                                    continue;
                                }
                                return false;
                            }
                        }
                        else
                        {
                            if (isBigOrSmallE(currentCharacter))
                            {
                                foundE = true;
                                continue;
                            }
                            if (currentCharacter == '.' && !usedDot)
                            {
                                usedDot = true;
                                continue;
                            }
                        }
                        return false;
                    }
                }
                return true;
            }
            else
            {
                // std::cout << "Character " << (*caracter) << " is NOT number nor \'+\' or \'-\'" << std::endl;
                return false;
            }
        }
    };
}