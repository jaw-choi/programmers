#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(int cnt,int curr, vector<int> numbers,int target)
{
    if(cnt==numbers.size()){
        if(curr==target)
            answer++;
        return;
    }
    
        DFS(cnt+1,curr+numbers[cnt],numbers,target);
        DFS(cnt+1,curr-numbers[cnt],numbers,target);
    
}
int solution(vector<int> numbers, int target) {
    
    DFS(0,0,numbers,target);

    return answer;
}