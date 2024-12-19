#include <string>
#include <vector>
#include <queue>

using namespace std;
int diff(string curr,string word)
{
    int answer = 0;
    for(int i=0;i<curr.length();i++)
        if(curr[i]!=word[i]){
            answer++;            
        }
    return answer;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string,int>> q;
    q.push({begin,0});
    vector<int> visited(50,0);
    while(!q.empty())
    {
        string curr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(curr == target)
            return cnt;
        
        for(int i=0;i<words.size();i++)
        {
            if(visited[i]) continue;
            if(diff(curr,words[i])==1){
                visited[i] = 1;
                q.push({words[i],cnt+1});    
            }
        }
    }
    return answer;
}