#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open = 0;
    for(auto c : s)
    {
        if(c=='(')
            open++;
        else
            open--;
        if(open<0)
            return false;
    }
    if(open!=0)
        return false;
    return answer;
}