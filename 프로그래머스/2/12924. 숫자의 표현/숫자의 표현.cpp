#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 등차수열의합 (+1)
int solution(int n) {
    int answer = 0;
    int pre = 0;
    for(int i=0;i<=n;i++)
    {
        pre += i;
        for(int j=i;j<=n;j++)
        {
            int result = j*(j+1)/2 - pre;
            //cout << result <<endl;
            if(result == n) answer++;
            else if(result<n)continue;
            else break;
        }
    }
    return answer;
}