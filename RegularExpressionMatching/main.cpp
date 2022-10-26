#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
    bool isMatch(const char *s, const char *p) {
       
        return false;
    }
    bool isMatch(string s, string p)
    {
        return isMatch(s.c_str(),p.c_str());
       
    }
};

int main()
{
    Solution solution;
    string s,p;
    cout << "Input the first string:" << endl;
    s="aa";
    //cin >> s;
    cout << endl;
    cout << "Input the filter:" << endl;
    p="?ab";
    //cin >> p;
    cout  << endl;
    cout << "The result is:" << solution.isMatch(s, p) << endl;
    return 0;
}