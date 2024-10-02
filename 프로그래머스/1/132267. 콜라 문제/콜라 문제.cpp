#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int tmp = 0;
    int remain = 0;
    while(n>=a)
    {
        tmp = n / a;
        remain = n % a;
        answer += tmp * b;
        n = remain + tmp * b;
    }
    return answer;
}