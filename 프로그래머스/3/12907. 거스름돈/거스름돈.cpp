#include <string>
#include <vector>
#define MODULER 1000000007
using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    int DP[100000];
    DP[0]=1;
    for(int i=0;i<money.size();i++)
    {
        for(int j = money[i];j<=n;j++)
        {
            DP[j] += DP[j - money[i]];
            DP[j] %= MODULER;

        }
    }
    return DP[n];
}

//1 - 1
//2 11,2  - 2
//3 111,12 - 2
//4 1111,112,22 - 3
//5,11111,1112,122,5 - 4

//6 111111,11112,1122,222,15 - 5

//1 1,0,0
//2 