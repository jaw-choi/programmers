#include <string>
#include <vector>
#include <iostream>


using namespace std;
int answer = 0;

void DFS(int idx,int curr,const vector<int>& numbers,int target)
{
    if(idx==numbers.size()){
        if(curr==target)
            answer++;
        return;
    }
    DFS(idx+1,curr+numbers[idx],numbers,target);
    DFS(idx+1,curr-numbers[idx],numbers,target);        
}

int solution(vector<int> numbers, int target) {
    DFS(0,0,numbers,target);    
    return answer;
}