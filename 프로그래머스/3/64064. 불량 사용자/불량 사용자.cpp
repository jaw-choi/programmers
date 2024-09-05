#include <string>
#include <vector>
#include <set>
#define MAX 8

using namespace std;
set <set<string>> ansList; 
bool visited[MAX] = {false};

bool check(string a, string b)
{
    if(a.length()!=b.length())
        return false;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i]!='*'&&b[i]!='*')
                return false;
        }
    }
    return true;
}

void DFS(vector<string>& a, vector<string>& b,int cnt, set<string> s)
{
    if(cnt==b.size())
    {
        ansList.insert(s);
        return;
    }
    for(int i=0;i<a.size();i++)
    {
        if(!check(a[i],b[cnt])||visited[i]==true)
            continue;
        set<string>tmp = s;
        tmp.insert(a[i]);
        visited[i]=true;
        DFS(a,b,cnt+1,tmp);
        visited[i]=false;
    }
    
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    set<string> s;
    DFS(user_id,banned_id,0,s);
    answer = ansList.size();
    return answer;
}