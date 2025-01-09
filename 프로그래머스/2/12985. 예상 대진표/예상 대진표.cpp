#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int round = 0;  // 몇 번째 라운드인지
    while (a != b) {  // 두 플레이어가 같은 번호가 될 때까지 반복
        a = (a + 1) / 2;  // 다음 라운드에서의 번호
        b = (b + 1) / 2;  // 다음 라운드에서의 번호
        round++;  // 라운드 증가
    }
    return round;
}