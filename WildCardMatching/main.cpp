#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    /* Given an parameter (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    *    '?' Matches any single character.
    *    '*' Matches any sequence of characters (including the empty sequence).
    * The matching should cover the entire input string (not partial).
    */
    bool isMatch(string s, string p) {
        bool anycharWorks=p[0]=='*';
        if(p.length()==1 && anycharWorks){
                return true;
            }
        int index=0;
        
        for(int i=0;i<p.length();i++){
            if(anycharWorks){
                while(index<s.length()){
                    if(s[index]==p[i]){
                        continue;
                    }
                }
                return false;
            }
            if(p[i]=='*'){
                anycharWorks = true;
                continue;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s;
    cout << "Input the first string:"<<endl;
    cin>>s;
    cout<<endl;
    cout << "Input the filter:"<<endl;
    string p;
    cin>>p;
    cout<<endl;
    cout << "The reuslt is:"<<solution.isMatch(s,p)<<endl;
    char in;
    cin >> in;
    return 0;
}