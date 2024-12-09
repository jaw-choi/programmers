#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    for(long long i = l-1;i<r;i++)
    {
        long long tmp = i;
        while(tmp >=5){
            if(tmp %5 ==2){
                break;
        }
            tmp /=5;
        }
        if(tmp %5 !=2){
            //cout <<i<<endl;
            answer++;
        }
    }
    /*
    1
    
    11011
    
    11011,11011,00000,11011,11011
    
    11011,11011,00000,11011,11011
    11011,11011,00000,11011,11011
    00000,00000,00000,00000,00000
    11011,11011,00000,11011,11011
    11011,11011,00000,11011,11011
    
    index / 5 = 3, index % 5= 1;
    index / 5 == 2 -> 0
    index / 5 == 0,1,3,4
        index % 5 == 2 ->0
    */

    return answer;
}