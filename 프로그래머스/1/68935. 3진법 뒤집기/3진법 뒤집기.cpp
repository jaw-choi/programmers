#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int index = 0;
    int tmp = n;
    vector<int> num{};
    index = log(n) / log(3);
    
    tmp = pow(3,index);
    int digit=0;
    while(n>0)
    {
        //25,18,
        if(n - tmp >= tmp)
            digit = 2;
        else if(n - tmp < 0)
            digit = 0;
        else 
            digit = 1;
        
        n = n - (tmp * digit);
        tmp = tmp / 3; 
        num.push_back(digit);
    }
    if(num.size() < index + 1)
    {
        while(num.size()!=index+1)
            num.push_back(0);
    }
    int tmpNum = 1;
    for(auto n : num)
    {
        answer += tmpNum * n;
        tmpNum*=3;
    }
    return answer;
}
//1200
//0021
//1 3 9 27