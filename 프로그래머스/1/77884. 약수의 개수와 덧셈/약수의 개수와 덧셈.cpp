#include <string>
#include <vector>
#include <iostream>

using namespace std;

int nums(int a)
{
    int ans=0;
    for(int i=1;i<=a;i++)
        if(a%i==0)
            ans++;
    return ans;
}
int solution(int left, int right) {
    int answer = 0;
    int tmp=0;
    while(left <= right)
    {
        tmp = nums(left);
        if(tmp%2==0)
            answer+=left;
        else
            answer-=left;
        left++;
    }
    return answer;
}