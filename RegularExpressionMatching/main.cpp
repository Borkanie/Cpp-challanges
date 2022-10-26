#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
    // we assume correct input
    bool isMatchRecursive(const char *s, const char *p)
    {
        if (*s == '\0' && *p == '\0')
        {
            return true;
        }
        // we check for repetition
        if (*(p + 1) == '*')
        {
            if (*p == '.')
            {
                while (*s != '\0')
                {
                    if (isMatchRecursive(s, p + 2))
                    {
                        return true;
                    }
                    else
                    {
                        s++;
                    }
                }
                return isMatchRecursive(s, p + 2);
            }
            else
            {
                while (*s == *p)
                {
                    if (isMatchRecursive(s, p + 2))
                    {
                        return true;
                    }
                    else
                    {
                        s++;
                    }
                }
                return isMatchRecursive(s, p + 2);
            }
        }
        // check for ANY
        if (*p == '.')
        {
            return isMatchRecursive(s + 1, p + 1);
        }
        // check for matching string
        if (*s == *p)
        {
            return isMatchRecursive(s + 1, p + 1);
        }

        return false;
    }

    bool isMatchNonRecursive(const char *s, const char *p)
    {
        const char *ss = s;
        const char *pp = p;
        while (*s != '\0' || *p != '\0')
        {
            // we check for repetition
            if (*(p + 1) == '*')
            {
                if (*p == '.')
                {
                    while (*s != '\0')
                    {
                        if (isMatchNonRecursive(s, p + 2))
                        {
                            return true;
                        }
                        else
                        {
                            s++;
                        }
                    }
                    s;
                    p+=2;
                    continue;
                }
                else
                {
                    while (*s == *p)
                    {
                        if (isMatchNonRecursive(s, p + 2))
                        {
                            return true;
                        }
                        else
                        {
                            s++;
                        }
                    }
                    s;
                    p+=2;
                    continue;
                }
            }
            // check for ANY
            if (*p == '.')
            {
                s++;
                p++;
                continue;
            }

            // check for matching string
            if (*s == *p)
            {
                s++;
                p++;
                continue;
            }

            return false;
        }
        return *s == '\0' && *p == '\0';
    }
    bool isMatch(string s, string p)
    {
        return isMatchRecursive(s.c_str(), p.c_str()) == isMatchNonRecursive(s.c_str(), p.c_str());
    }
};

int main()
{
    Solution solution;
    string s, p;
    cout << "Input the first string:" << endl;
    s = "bbabacccbcbbcaaab";
    // cin >> s;
    cout << endl;
    cout << "Input the filter:" << endl;
    p = "a*b*a*a*c*aa*c*bc*";
    // cin >> p;
    cout << endl;
    cout << "The result is:" << solution.isMatch(s, p) << endl;
    return 0;
}