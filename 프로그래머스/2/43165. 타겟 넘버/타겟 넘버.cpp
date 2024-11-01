#include <string>
#include <vector>

using namespace std;
void DFS(int curr,int sum,const vector<int>& numbers,int target,int& answer,int n)
{
    if(curr>=n){
        if(target==sum)
        {
            answer++;
        }
        return;
    }
    DFS(curr+1,sum+numbers[curr],numbers,target,answer,n);
    DFS(curr+1,sum-numbers[curr],numbers,target,answer,n);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(0,0,numbers,target,answer,numbers.size());
    return answer;
}