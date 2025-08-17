#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int palOdd(string& s, int idx)
{
    int cnt = 1;
    int k = 1;
    while(idx-k>=0 && idx+k<s.length())
    {
        if(s[idx-k]==s[idx+k])
            cnt+=2;
        else
            break;
        k++;
    }
    return cnt;
}
int palEven(string& s, int idx)
{
    if(idx+1>=s.length())
        return 0;
    int cnt = 0;
    int k = 0;
    while(idx-k>=0 && idx+k+1<s.length())
    {
        if(s[idx-k]==s[idx+k+1])
            cnt+=2;
        else
            break;
        k++;
    }
    return cnt;
}
int solution(string s)
{
    int answer=0;
    for(int i=0;i<s.length();i++)
    {
        int tmp = max(palOdd(s,i),palEven(s,i));
        //cout << palOdd(s,i) << " " << palEven(s,i) << endl;
        answer = max(answer,tmp);
    }

    return answer;
}