#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int check(string s,int left, int right)
{
    int answer = 0;
    while(left>=0 && right < s.length())
    {
        if(s[left]!=s[right])
            break;
        left--,right++;
    }
    //33
    //24
    //15
    //06
    //-17
    return right - left - 1;
}
int solution(string s)
{
    if(s.length()==1)
        return 1;
    int answer= 0;
    for(int i=0; i <s.length();i++)
    {
        int odd = check(s,i,i);
        int even = check(s,i-1,i);
        answer = max(answer,max(odd,even));
    }
   

    return answer;
}