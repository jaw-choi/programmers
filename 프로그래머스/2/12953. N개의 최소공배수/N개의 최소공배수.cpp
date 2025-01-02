#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

// 소인수 분해 함수
void countPrimeFactors(int n, map<int, int>& mp) {
    for (int i = 2; i * i <= n; i++) {
        int tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        if (tmp > 0) {
            mp[i] = max(mp[i], tmp); // 최대 지수 저장
        }
    }
    if (n > 1) {
        mp[n] = max(mp[n], 1); // 마지막 남은 소수 처리
    }
}

// 최소공배수 계산 함수
int solution(vector<int> arr) {
    long long answer = 1; // 오버플로우 방지
    map<int, int> mp;

    // 각 숫자에 대해 소인수 분해
    for (auto a : arr) {
        countPrimeFactors(a, mp);
    }

    // 소인수의 최대 지수를 곱하여 최소공배수 계산
    for (auto m : mp) {
        for (int i = 0; i < m.second; i++) {
            
            answer *= m.first;
        }
    }
    return static_cast<int>(answer);
}
