#include <string>
#include <vector>
#define INF 100000
using namespace std;
bool canBeChanged(string a, string b)
{
    int cnt=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i])
            cnt++;
        if(cnt>=2)
            return false;
    }
    return true;
}
void dfs(int cnt, string curr, const string& target, const vector<string>& words, vector<int>& visited, int& answer) {

    if(curr==target){
        answer = min(answer,cnt);
        return;
    }
    for(int i=0;i<words.size();i++)
    {
        if(!visited[i]&&canBeChanged(curr,words[i])){
            visited[i] = 1;
            dfs(cnt+1,words[i],target,words,visited,answer);
            visited[i]=0;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = INF;
    vector<int> visited(words.size(), 0); 
    dfs(0,begin,target,words,visited,answer);
    if(answer==INF)
        return 0;
    return answer;
}