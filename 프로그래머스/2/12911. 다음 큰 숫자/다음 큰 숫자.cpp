#include <string>
#include <vector>
#define INF 2000001
using namespace std;

int oneNum(int num)
{
    int ans = 0;
    while(num!=0)
    {
        if(num&1)
            ans++;
        num = num>>1;
    }
    return ans;
}

bool helper(int i, int n)
{
    if(oneNum(i)==oneNum(n))
        return true;
    return false;
}

int solution(int n) {
    int answer = 0;
    for(int i = n+1;i<INF;i++)
    {
        if(helper(i,n))
            return i;
    }
    return answer;
}