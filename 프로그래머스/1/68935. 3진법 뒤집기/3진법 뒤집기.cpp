#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num{};
    while(n!=0)
    {
        num.push_back(n%3);
        n/=3;
    }
    int tmp = 1;
    while(num.size()!=0)
    {
        answer += num.back() * tmp;
        num.pop_back();
        tmp*=3;
    }
    return answer;
}
