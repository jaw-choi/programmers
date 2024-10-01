#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool check(long long n) {
    if (n <= 1) return false; // 1 이하는 소수가 아님
    if (n == 2 || n == 3) return true; // 2와 3은 소수
    if (n % 2 == 0 || n % 3 == 0) return false; // 2와 3으로 나누어 떨어지면 소수가 아님

    // 6k +/- 1 형태의 수를 검사하여 소수 여부 확인
    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num = "";
    //k진수로 변경
    while(n>0)
    {
        char tmp = (n%k) + '0';
        num = tmp + num;
        n/=k;
    }
    //string p = "";
    bool flag = false;
    long long prime = 0;
    int startIdx = 0;
    int endIdx = 0;
    //cout << num << endl;
    string tmp = "";
    for (char c : num) { 
        if (c == '0') { 
            if (!tmp.empty() && check(stoll(tmp))) {
                answer++; 
            } 
            tmp = ""; 
        } 
        else tmp += c; 
    }
    if (!tmp.empty() && check(stoll(tmp))) {  //마지막꺼 
        answer++;
    } 
            
    
    
    return answer;
}