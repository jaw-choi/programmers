#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num)
{
    int cnt = 2;
    while(num>cnt){
        if(num%cnt==0)
            return false;
        cnt++;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int tmp = nums[i]+nums[j]+nums[k];
                if(isPrime(tmp))
                    answer++;
            }
        }
    }
    
    return answer;
}