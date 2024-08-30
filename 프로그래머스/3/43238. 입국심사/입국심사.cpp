#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 1;
    long long right = n * (long long)times.back();
    while(left <= right)
    {
        long long num = 0;
        long long mid = (left + right) / 2;
        for(long long t : times)
        {
            num += mid / t;
        }
        if(num >= n){
            right = mid - 1;
            answer = mid;
        }            
        else
            left = mid + 1;
    }
    return answer;
}